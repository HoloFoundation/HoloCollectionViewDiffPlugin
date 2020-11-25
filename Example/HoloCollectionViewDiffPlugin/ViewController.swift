//
//  ViewController.swift
//  HoloCollectionViewDiffPlugin
//
//  Created by gonghonglou on 11/25/2020.
//  Copyright (c) 2020 gonghonglou. All rights reserved.
//

import UIKit
import HoloCollectionView
import HoloCollectionViewDiffPlugin

class ViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        self.view.addSubview(reloadButton)
        self.view.addSubview(self.collectionView)
    }
    
    @objc func reloadButtonAction() {
        self.collectionView.holo_removeAllSections()
        self.collectionView.holo_makeRows { (make) in
            DataSet.generateItems().forEach { (item) in
                _ = make.row(CollectionViewCell.self).willDisplayHandler { (cell, model) in
                    guard let cell = cell as? CollectionViewCell else { return }
                    cell.configTitle("\(item)")
                }.diffId(item)
            }
        }
        self.collectionView.reload()
    }
    
    
    lazy var reloadButton: UIButton = {
        let _reloadButton = UIButton.init(type: .system)
        _reloadButton.setTitle("reload", for: .normal)
        _reloadButton.layer.borderColor = UIColor.systemBlue.cgColor
        _reloadButton.layer.borderWidth = 1
        _reloadButton.layer.cornerRadius = 5
        _reloadButton.frame = CGRect(x: 50, y: 44, width: HOLO_SCREEN_WIDTH - 100, height: 44)
        _reloadButton.addTarget(self, action: #selector(ViewController.reloadButtonAction), for: .touchUpInside)
        return _reloadButton
    }()
    
    lazy var collectionView: UICollectionView = {
        let flowLayout = UICollectionViewFlowLayout()
        flowLayout.sectionInset = UIEdgeInsets(top: 10, left: 10, bottom: 10, right: 10)
        flowLayout.minimumLineSpacing = 10
        flowLayout.minimumInteritemSpacing = 10
        flowLayout.itemSize = CGSize(width: (HOLO_SCREEN_WIDTH-30)/2, height: 100)
        
        let _collectionView = UICollectionView.init(frame: CGRect.zero, collectionViewLayout: flowLayout)
        _collectionView.backgroundColor = UIColor.white
        _collectionView.frame = CGRect(x: 0, y: 100, width: HOLO_SCREEN_WIDTH, height: HOLO_SCREEN_HEIGHT - 100)
        
        return _collectionView
    }()
    
    let HOLO_SCREEN_WIDTH = UIScreen.main.bounds.size.width
    let HOLO_SCREEN_HEIGHT = UIScreen.main.bounds.size.height

}

struct DataSet {
  static func generateItems() -> [Int] {
    let count = Int(arc4random_uniform(20)) + 10
    let items = Array(0..<count)
    return items.shuffled()
  }
}

