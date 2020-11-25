//
//  UICollectionView+DiffPlugin.swift
//  HoloCollectionViewDiffPlugin
//
//  Created by 与佳期 on 2020/11/25.
//

import UIKit
import DeepDiff
import HoloCollectionView

public extension UICollectionView {
    
    func stored() {
        self.diffOldData = self.holo_proxy.proxyData.sections
    }

    
    func reload (
        sectionTag: String? = nil,
        updateData: (() -> Void)? = nil,
        completion: ((Bool) -> Void)? = nil) {
        
        var section: HoloCollectionSection?
        var index = 0
        
        if sectionTag == nil {
            section = self.holo_proxy.proxyData.sections.first
            index = 0
        } else {
            section = self.holo_proxy.proxyData.section(withTag: sectionTag)
            if let section = section, let idx = self.holo_proxy.proxyData.sections.firstIndex(of: section) {
                index = idx
            }
        }
        
        if section == nil {
            debugPrint("[HoloCollectionView] No found a section with the tag: \(sectionTag ?? "nil").")
            return
        }
        
        var oldItems = [HoloCollectionRow]()
        if let diffOldData = self.diffOldData, diffOldData.count > index, let items = diffOldData[index].rows {
            oldItems = items
        }
        let items = section?.rows ?? [HoloCollectionRow]()
        let changes = diff(old: oldItems, new: items)
        
        self.reload(changes: changes,
                    section: index,
                    updateData: {
                        self.diffOldData = self.holo_proxy.proxyData.sections
                        updateData?()
                    },
                    completion: completion
        )
    }
    
}

extension UICollectionView {
    
    static var kHoloCollectionViewDiffOldDataKey = "kHoloCollectionViewDiffOldDataKey"
    
    var diffOldData: [HoloCollectionSection]? {
        set {
            objc_setAssociatedObject(self, &UICollectionView.kHoloCollectionViewDiffOldDataKey, newValue, objc_AssociationPolicy.OBJC_ASSOCIATION_COPY_NONATOMIC)
        }
        get {
            return objc_getAssociatedObject(self, &UICollectionView.kHoloCollectionViewDiffOldDataKey) as? [HoloCollectionSection]
        }
    }
    
}

