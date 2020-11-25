#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "HoloCollectionViewMacro.h"
#import "HoloCollectionViewCellProtocol.h"
#import "HoloCollectionViewFooterProtocol.h"
#import "HoloCollectionViewHeaderFooterProtocol.h"
#import "HoloCollectionViewHeaderProtocol.h"
#import "HoloCollectionViewProtocol.h"
#import "UICollectionView+HoloCollectionView.h"
#import "HoloCollectionView.h"
#import "HoloCollectionViewMaker.h"
#import "HoloCollectionRow.h"
#import "HoloCollectionRowMaker.h"
#import "HoloCollectionViewRowMaker.h"
#import "HoloCollectionSection.h"
#import "HoloCollectionSectionMaker.h"
#import "HoloCollectionViewSectionMaker.h"
#import "HoloCollectionViewUpdateRowMaker.h"
#import "HoloCollectionViewProxy.h"
#import "HoloCollectionViewProxyData.h"
#import "UICollectionView+HoloCollectionViewProxy.h"

FOUNDATION_EXPORT double HoloCollectionViewVersionNumber;
FOUNDATION_EXPORT const unsigned char HoloCollectionViewVersionString[];

