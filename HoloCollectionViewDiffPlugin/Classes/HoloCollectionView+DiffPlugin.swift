//
//  HoloCollectionView+DiffPlugin.swift
//  HoloCollectionViewDiffPlugin
//
//  Created by 与佳期 on 2020/11/25.
//

import Foundation
import DeepDiff
import HoloCollectionView

public extension HoloCollectionRowMaker {
    
    func diffId(_ diffId: AnyHashable) -> Self {
        let row = self.fetchCollectionRow()
        row.diffId = diffId
        return self
    }
    
}

extension HoloCollectionRow: DiffAware {
    
    static var kHoloCollectionRowDiffIdKey = "kHoloCollectionRowDiffIdKey"
    
    public var diffId: AnyHashable? {
        set {
            objc_setAssociatedObject(self, &HoloCollectionRow.kHoloCollectionRowDiffIdKey, newValue, objc_AssociationPolicy.OBJC_ASSOCIATION_RETAIN_NONATOMIC)
        }
        get {
            return objc_getAssociatedObject(self, &HoloCollectionRow.kHoloCollectionRowDiffIdKey) as? AnyHashable
        }
    }
    
    public static func compareContent(_ a: HoloCollectionRow, _ b: HoloCollectionRow) -> Bool {
        return a.diffId != nil && b.diffId != nil && a.diffId == b.diffId
    }
    
}
