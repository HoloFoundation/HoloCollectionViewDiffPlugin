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
    
    /// Stored old sections data
    func stored() {
        self.diffOldData = self.holo_proxy.proxyData.sections
    }

    /// Animate reload in a batch update
    ///
    /// - Parameters:
    ///   - sectionTag: Tag of the section that all calculated IndexPath belong
    ///   - updateData: Update your data source model
    ///   - completion: Called when operation completes
    func reload (
        sectionTag: String? = nil,
        updateData: (() -> Void)? = nil,
        completion: ((Bool) -> Void)? = nil) {
        
        var targetSection: HoloCollectionSection? = nil
        for item in self.holo_proxy.proxyData.sections {
            if item.tag == sectionTag || (item.tag == nil && sectionTag == nil) {
                targetSection = item
                break
            }
        }
        guard let section = targetSection,
              let index = self.holo_proxy.proxyData.sections.firstIndex(of: section) else {
            debugPrint("[HoloCollectionViewDiffPlugin] No found a section with the tag: \(sectionTag ?? "nil").")
            return
        }
        
        var oldItems: [HoloCollectionItem]
        if let diffOldData = self.diffOldData, diffOldData.count > index {
            oldItems = diffOldData[index].items
        } else {
            oldItems = [HoloCollectionItem]()
        }
        let newItems = section.items
        let changes = diff(old: oldItems, new: newItems)
        
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

