# HoloCollectionViewDiffPlugin

[![CI Status](https://img.shields.io/travis/HoloFoundation/HoloCollectionViewDiffPlugin.svg?style=flat)](https://travis-ci.org/HoloFoundation/HoloCollectionViewDiffPlugin)
[![Version](https://img.shields.io/cocoapods/v/HoloCollectionViewDiffPlugin.svg?style=flat)](https://cocoapods.org/pods/HoloCollectionViewDiffPlugin)
[![License](https://img.shields.io/cocoapods/l/HoloCollectionViewDiffPlugin.svg?style=flat)](https://cocoapods.org/pods/HoloCollectionViewDiffPlugin)
[![Platform](https://img.shields.io/cocoapods/p/HoloCollectionViewDiffPlugin.svg?style=flat)](https://cocoapods.org/pods/HoloCollectionViewDiffPlugin)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## What's for

HoloCollectionViewDiffPlugin is a plugin for [HoloCollectionView](https://github.com/gonghonglou/HoloCollectionView) framework, which provide the diff reload actions support for [DeepDiff](https://github.com/onmyway133/DeepDiff).

To use it, simply make sure you use DeepDiff and import this plugin.

## Usage

```swift
let collectionView = UICollectionView.init(frame: self.view.bounds, collectionViewLayout: flowLayout)
self.view.addSubview(collectionView)

collectionView.holo_makeRows { (make) in
    for item in [Int]() {
        _ = make.row(CollectionViewCell.self).model(item).diffId(item)
    }
}
collectionView.reloadData()

// diff reload
collectionView.stored()

collectionView.holo_removeAllSections()
collectionView.holo_makeRows { (make) in
    for item in [Int]() {
        _ = make.row(CollectionViewCell.self).model(item).diffId(item)
    }
}

collectionView.reload()
```
If the collectionView has been reload and then you want to diff reload, you need to perform `collectionView.stored()` before `collectionView.holo_makeRows{}`.

## Installation

HoloCollectionViewDiffPlugin is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'HoloCollectionViewDiffPlugin'
```

## Author

gonghonglou, gonghonglou@icloud.com

## License

HoloCollectionViewDiffPlugin is available under the MIT license. See the LICENSE file for more info.
