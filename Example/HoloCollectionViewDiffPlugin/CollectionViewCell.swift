//
//  CollectionViewCell.swift
//  HoloCollectionViewDiffPlugin_Example
//
//  Created by 与佳期 on 2020/11/25.
//  Copyright © 2020 CocoaPods. All rights reserved.
//

import UIKit

class CollectionViewCell: UICollectionViewCell {
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        
        self.label.frame = self.contentView.bounds
        self.contentView.addSubview(self.label)
    }

    func configTitle(_ title: String) {
        self.label.text = title
    }

    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    lazy var label: UILabel = {
        let _label = UILabel()
        _label.backgroundColor = UIColor.systemBlue
        _label.textColor = .white
        _label.layer.cornerRadius = 5
        _label.layer.masksToBounds = true
        _label.textAlignment = .center
        return _label
    }()
}
