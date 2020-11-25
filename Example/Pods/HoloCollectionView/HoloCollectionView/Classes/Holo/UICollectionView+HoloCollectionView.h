//
//  UICollectionView+HoloCollectionView.h
//  HoloCollectionView
//
//  Created by 与佳期 on 2019/9/13.
//

#import <UIKit/UIKit.h>
@class HoloCollectionViewMaker, HoloCollectionViewRowMaker, HoloCollectionViewSectionMaker, HoloCollectionViewUpdateRowMaker;

NS_ASSUME_NONNULL_BEGIN

@interface UICollectionView (HoloCollectionView)

#pragma mark - collectionView
/**
 *  Creates a HoloCollectionViewMaker in the callee for current UICollectionView.
 *
 *  @param block Scope within which you can configure the current UICollectionView.
 */
- (void)holo_makeCollectionView:(void(NS_NOESCAPE ^)(HoloCollectionViewMaker *make))block;


#pragma mark - section
/**
 *  Creates a HoloCollectionViewSectionMaker in the callee for current UICollectionView.
 *  Append these sections in the callee to the data source, don't care about tag of the section.
 *
 *  @param block Scope within which you can create some sections which you wish to apply to current UICollectionView.
 */
- (void)holo_makeSections:(void(NS_NOESCAPE ^)(HoloCollectionViewSectionMaker *make))block;

/**
 *  Creates a HoloCollectionViewSectionMaker in the callee for current UICollectionView.
 *  Append these sections in the callee to the data source, don't care about tag of the section.
 *
 *  Refresh current UICollectionView automatically.
 *
 *  @param block Scope within which you can create some sections which you wish to apply to current UICollectionView.
 *  @param autoReload Auto reload view if YES.
 */
- (void)holo_makeSections:(void(NS_NOESCAPE ^)(HoloCollectionViewSectionMaker *make))block
               autoReload:(BOOL)autoReload;

/**
 *  Creates a HoloCollectionViewSectionMaker in the callee for current UICollectionView.
 *  Insert these sections in the callee to the data source, don't care about tag of the section.
 *
 *  @param index The index in the array at which to insert sections. If this value is less than 0, insert an first index; if this value is greater than the count of elements in the array, insert an last index.
 *  @param block Scope within which you can create some sections which you wish to apply to current UICollectionView.
 */
- (void)holo_insertSectionsAtIndex:(NSInteger)index
                             block:(void(NS_NOESCAPE ^)(HoloCollectionViewSectionMaker *make))block;

/**
 *  Creates a HoloCollectionViewSectionMaker in the callee for current UICollectionView.
 *  Insert these sections in the callee to the data source, don't care about tag of the section.
 *
 *  Refresh current UICollectionView automatically.
 *
 *  @param index The index in the array at which to insert sections. If this value is less than 0, insert an first index; if this value is greater than the count of elements in the array, insert an last index.
 *  @param block Scope within which you can create some sections which you wish to apply to current UICollectionView.
 *  @param autoReload Auto reload view if YES.
 */
- (void)holo_insertSectionsAtIndex:(NSInteger)index
                             block:(void(NS_NOESCAPE ^)(HoloCollectionViewSectionMaker *make))block
                        autoReload:(BOOL)autoReload;

/**
 *  Creates a HoloCollectionViewSectionMaker in the callee for current UICollectionView.
 *  Update these sections in the callee for current UICollectionView.
 *  If current UICollectionView don't contain some sections in the callee, ignore them.
 *
 *  @param block Scope within which you can create some sections which you wish to apply to current UICollectionView.
 */
- (void)holo_updateSections:(void(NS_NOESCAPE ^)(HoloCollectionViewSectionMaker *make))block;

/**
 *  Creates a HoloCollectionViewSectionMaker in the callee for current UICollectionView.
 *  Update these sections in the callee for current UICollectionView.
 *  If current UICollectionView don't contain some sections in the callee, ignore them.
 *
 *  Refresh current UICollectionView automatically.
 *
 *  @param block Scope within which you can create some sections which you wish to apply to current UICollectionView.
 *  @param autoReload Auto reload view if YES.
 */
- (void)holo_updateSections:(void(NS_NOESCAPE ^)(HoloCollectionViewSectionMaker *make))block
                 autoReload:(BOOL)autoReload;

/**
 *  Creates a HoloCollectionViewSectionMaker in the callee for current UICollectionView.
 *  Remake these sections (Reinit all properties) in the callee for current UICollectionView.
 *  If current UICollectionView don't contain some sections in the callee, ignore them.
 *
 *  @param block Scope within which you can create some sections which you wish to apply to current UICollectionView.
 */
- (void)holo_remakeSections:(void(NS_NOESCAPE ^)(HoloCollectionViewSectionMaker *make))block;

/**
 *  Creates a HoloCollectionViewSectionMaker in the callee for current UICollectionView.
 *  Remake these sections (Reinit all properties) in the callee for current UICollectionView.
 *  If current UICollectionView don't contain some sections in the callee, ignore them.
 *
 *  Refresh current UICollectionView automatically.
 *
 *  @param block Scope within which you can create some sections which you wish to apply to current UICollectionView.
 *  @param autoReload Auto reload view if YES.
 */
- (void)holo_remakeSections:(void(NS_NOESCAPE ^)(HoloCollectionViewSectionMaker *make))block
                 autoReload:(BOOL)autoReload;

/**
 *  Remove all sections.
 */
- (void)holo_removeAllSections;

/**
 *  Remove all sections.
 *
 *  Refresh current UICollectionView automatically.
 *
 *  @param autoReload Auto reload view if YES.
 */
- (void)holo_removeAllSectionsAutoReload:(BOOL)autoReload;
- (void)holo_removeAllSectionsautoReload:(BOOL)autoReload DEPRECATED_MSG_ATTRIBUTE("Please use `holo_removeAllSectionsAutoReload:` api instead. This method will be deleted soon.");

/**
 *  Remove the sections according to the tags.
 *
 *  @param tags The tags of sections which you wish to remove.
 */
- (void)holo_removeSections:(NSArray<NSString *> *)tags;

/**
 *  Remove the sections according to the tags.
 *
 *  Refresh current UICollectionView automatically.
 *
 *  @param tags The tags of sections which you wish to remove.
 *  @param autoReload Auto reload view if YES.
 */
- (void)holo_removeSections:(NSArray<NSString *> *)tags
                 autoReload:(BOOL)autoReload;


#pragma mark - row
/**
 *  Creates a HoloCollectionViewRowMaker in the callee for current UICollectionView.
 *  Append these rows in the callee to defult section of UICollectionView.
 *  If current UICollectionView don't contain any section, create a new one and append it to the data source.
 *
 *  @param block Scope within which you can create some rows which you wish to apply to current UICollectionView.
 */
- (void)holo_makeRows:(void(NS_NOESCAPE ^)(HoloCollectionViewRowMaker *make))block;

/**
 *  Creates a HoloCollectionViewRowMaker in the callee for current UICollectionView.
 *  Append these rows in the callee to defult section of UICollectionView.
 *  If current UICollectionView don't contain any section, create a new one and append it to the data source.
 *
 *  Refresh current UICollectionView automatically.
 *
 *  @param block Scope within which you can create some rows which you wish to apply to current UICollectionView.
 *  @param autoReload Auto reload view if YES.
 */
- (void)holo_makeRows:(void(NS_NOESCAPE ^)(HoloCollectionViewRowMaker *make))block
           autoReload:(BOOL)autoReload;

/**
 *  Creates a HoloCollectionViewRowMaker in the callee for current UICollectionView.
 *  Append these rows in the callee to a section according to the tag.
 *  If current UICollectionView don't contain a section with the tag, create a new one with the tag and append it to the data source.
 *
 *  @param tag The tag of section which you wish to append rows.
 *  @param block Scope within which you can create some rows which you wish to apply to current UICollectionView.
 */
- (void)holo_makeRowsInSection:(NSString *)tag
                         block:(void(NS_NOESCAPE ^)(HoloCollectionViewRowMaker *make))block;

/**
 *  Creates a HoloCollectionViewRowMaker in the callee for current UICollectionView.
 *  Append these rows in the callee to a section according to the tag.
 *  If current UICollectionView don't contain a section with the tag, create a new one with the tag and append it to the data source.
 *
 *  Refresh current UICollectionView automatically.
 *
 *  @param tag The tag of section which you wish to append rows.
 *  @param block Scope within which you can create some rows which you wish to apply to current UICollectionView.
 *  @param autoReload Auto reload view if YES.
 */
- (void)holo_makeRowsInSection:(NSString *)tag
                         block:(void(NS_NOESCAPE ^)(HoloCollectionViewRowMaker *make))block
                    autoReload:(BOOL)autoReload;

/**
 *  Creates a HoloCollectionViewRowMaker in the callee for current UICollectionView.
 *  Append these rows in the callee to defult section of UICollectionView.
 *  If current UICollectionView don't contain any section, create a new one and append it to the data source.
 *
 *  @param index The index in the array at which to insert rows. If this value is less than 0, insert an first index; if this value is greater than the count of elements in the array, insert an last index.
 *  @param block Scope within which you can create some rows which you wish to apply to current UICollectionView.
 */
- (void)holo_insertRowsAtIndex:(NSInteger)index
                         block:(void(NS_NOESCAPE ^)(HoloCollectionViewRowMaker *make))block;

/**
 *  Creates a HoloCollectionViewRowMaker in the callee for current UICollectionView.
 *  Insert these rows in the callee to defult section of UICollectionView.
 *  If current UICollectionView don't contain any section, create a new one and append it to the data source.
 *
 *  Refresh current UICollectionView automatically.
 *
 *  @param index The index in the array at which to insert rows. If this value is less than 0, insert an first index; if this value is greater than the count of elements in the array, insert an last index.
 *  @param block Scope within which you can create some rows which you wish to apply to current UICollectionView.
 *  @param autoReload Auto reload view if YES.
 */
- (void)holo_insertRowsAtIndex:(NSInteger)index
                         block:(void(NS_NOESCAPE ^)(HoloCollectionViewRowMaker *make))block
                    autoReload:(BOOL)autoReload;

/**
 *  Creates a HoloCollectionViewRowMaker in the callee for current UICollectionView.
 *  Insert these rows in the callee to a section according to the tag.
 *  If current UICollectionView don't contain a section with the tag, create a new one with the tag and append it to the data source.
 *
 *  @param index The index in the array at which to insert rows. If this value is less than 0, insert an first index; if this value is greater than the count of elements in the array, insert an last index.
 *  @param tag The tag of section which you wish to append rows.
 *  @param block Scope within which you can create some rows which you wish to apply to current UICollectionView.
 */
- (void)holo_insertRowsAtIndex:(NSInteger)index
                     inSection:(NSString *)tag
                         block:(void(NS_NOESCAPE ^)(HoloCollectionViewRowMaker *make))block;

/**
 *  Creates a HoloCollectionViewRowMaker in the callee for current UICollectionView.
 *  Insert these rows in the callee to a section according to the tag.
 *  If current UICollectionView don't contain a section with the tag, create a new one with the tag and append it to the data source.
 *
 *  Refresh current UICollectionView automatically.
 *
 *  @param index The index in the array at which to insert rows. If this value is less than 0, insert an first index; if this value is greater than the count of elements in the array, insert an last index.
 *  @param tag The tag of section which you wish to append rows.
 *  @param block Scope within which you can create some rows which you wish to apply to current UICollectionView.
 *  @param autoReload Auto reload view if YES.
 */
- (void)holo_insertRowsAtIndex:(NSInteger)index
                     inSection:(NSString *)tag
                         block:(void(NS_NOESCAPE ^)(HoloCollectionViewRowMaker *make))block
                    autoReload:(BOOL)autoReload;

/**
 *  Creates a HoloCollectionViewUpdateRowMaker in the callee for current UICollectionView.
 *  Update these rows in the callee for current UICollectionView.
 *  If current UICollectionView don't contain these rows, ignore them.
 *
 *  @param block Scope within which you can create some rows which you wish to apply to current UICollectionView.
 */
- (void)holo_updateRows:(void(NS_NOESCAPE ^)(HoloCollectionViewUpdateRowMaker *make))block;

/**
 *  Creates a HoloCollectionViewUpdateRowMaker in the callee for current UICollectionView.
 *  Update these rows in the callee for current UICollectionView.
 *  If current UICollectionView don't contain these rows, ignore them.
 *
 *  Refresh current UICollectionView automatically.
 *
 *  @param block Scope within which you can create some rows which you wish to apply to current UICollectionView.
 *  @param autoReload Auto reload view if YES.
 */
- (void)holo_updateRows:(void(NS_NOESCAPE ^)(HoloCollectionViewUpdateRowMaker *make))block
             autoReload:(BOOL)autoReload;

/**
 *  Creates a HoloCollectionViewUpdateRowMaker in the callee for current UICollectionView.
 *  Remake these rows (Reinit all properties) in the callee for current UICollectionView.
 *  If current UICollectionView don't contain these rows, ignore them.
 *
 *  @param block Scope within which you can create some rows which you wish to apply to current UICollectionView.
 */
- (void)holo_remakeRows:(void(NS_NOESCAPE ^)(HoloCollectionViewUpdateRowMaker *make))block;

/**
 *  Creates a HoloCollectionViewUpdateRowMaker in the callee for current UICollectionView.
 *  Remake these rows (Reinit all properties) in the callee for current UICollectionView.
 *  If current UICollectionView don't contain these rows, ignore them.
 *
 *  Refresh current UICollectionView automatically.
 *
 *  @param block Scope within which you can create some rows which you wish to apply to current UICollectionView.
 *  @param autoReload Auto reload view if YES.
 */
- (void)holo_remakeRows:(void(NS_NOESCAPE ^)(HoloCollectionViewUpdateRowMaker *make))block
             autoReload:(BOOL)autoReload;

/**
 *  Remove all rows in the sections according to the tags.
 *
 *  @param tags The tags of sections which you wish to remove all rows.
 */
- (void)holo_removeAllRowsInSections:(NSArray<NSString *> *)tags;

/**
 *  Remove all rows in the sections according to the tags.
 *
 *  @param tags The tags of sections which you wish to remove all rows.
 *  @param autoReload Auto reload view if YES.
 */
- (void)holo_removeAllRowsInSections:(NSArray<NSString *> *)tags
                          autoReload:(BOOL)autoReload;

/**
 *  Remove the rows according to the tags in all sections.
 *
 *  @param tags The tags of rows which you wish to remove.
 */
- (void)holo_removeRows:(NSArray<NSString *> *)tags;

/**
 *  Remove the rows according to the tags in all sections.
 *
 *  Refresh current UICollectionView automatically.
 *
 *  @param tags The tags of rows which you wish to remove.
 *  @param autoReload Auto reload view if YES.
 */
- (void)holo_removeRows:(NSArray<NSString *> *)tags
             autoReload:(BOOL)autoReload;

@end

NS_ASSUME_NONNULL_END