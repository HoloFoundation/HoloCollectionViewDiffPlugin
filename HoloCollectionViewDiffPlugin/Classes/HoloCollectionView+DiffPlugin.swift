//
//  HoloCollectionView+DiffPlugin.swift
//  HoloCollectionViewDiffPlugin
//
//  Created by 与佳期 on 2020/11/25.
//

import Foundation
import DeepDiff
import HoloCollectionView

public extension HoloCollectionItemMaker {
    
    /// Diff id
    @discardableResult
    func diffId(_ diffId: AnyHashable) -> Self {
        let item = self.fetchCollectionItem()
        item.diffId = diffId
        return self
    }
    
}

extension HoloCollectionItem: DiffAware {
    
    static var kHoloCollectionItemDiffIdKey = "kHoloCollectionItemDiffIdKey"
    
    public var diffId: AnyHashable? {
        set {
            objc_setAssociatedObject(self, &HoloCollectionItem.kHoloCollectionItemDiffIdKey, newValue, objc_AssociationPolicy.OBJC_ASSOCIATION_RETAIN_NONATOMIC)
        }
        get {
            return objc_getAssociatedObject(self, &HoloCollectionItem.kHoloCollectionItemDiffIdKey) as? AnyHashable
        }
    }
    
    public static func compareContent(_ a: HoloCollectionItem, _ b: HoloCollectionItem) -> Bool {
        return a.diffId != nil && b.diffId != nil && a.diffId == b.diffId
    }
    
}
