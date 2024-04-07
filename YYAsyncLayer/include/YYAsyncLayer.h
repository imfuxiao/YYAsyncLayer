//
//  YYAsyncLayer.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 15/4/11.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIKit.h>

#import "YYSentinel.h"
#import "YYTransaction.h"

@class YYAsyncLayerDisplayTask;

// 这是一个 macro。
// https://developer.apple.com/documentation/swift/designating-nullability-in-objective-c-apis#Annotate-Regions-as-Nonnullable
NS_ASSUME_NONNULL_BEGIN

/**
 The YYAsyncLayer class is a subclass of CALayer used for render contents asynchronously.
 YYAsyncLayer 类是 CALayer 的子类，用于异步呈现内容。
 
 @discussion When the layer need update it's contents, it will ask the delegate
 for a async display task to render the contents in a background queue.
 
 @discussion 当图层需要更新内容时，它会向 delegate 请求一个异步显示任务，在后台队列中渲染内容。
 */
@interface YYAsyncLayer : CALayer
/// Whether the render code is executed in background. Default is YES.
/// 是否在后台执行渲染代码。默认为 "是"。
@property BOOL displaysAsynchronously;
@end


/**
 The YYAsyncLayer's delegate protocol. The delegate of the YYAsyncLayer (typically a UIView)
 must implements the method in this protocol.
 
 YYAsyncLayer 的委托协议。YYAsyncLayer 的委托（通常是 UIView）必须实现该协议中的方法。
 */
@protocol YYAsyncLayerDelegate <NSObject>
@required
/// This method is called to return a new display task when the layer's contents need update.
/// 当需要更新图层内容时，调用此方法返回新的显示任务。
- (YYAsyncLayerDisplayTask *)newAsyncDisplayTask;
@end


/**
 A display task used by YYAsyncLayer to render the contents in background queue.
 
 YYAsyncLayer 用于在后台队列中渲染内容的显示任务。
 */
@interface YYAsyncLayerDisplayTask : NSObject

/**
 This block will be called before the asynchronous drawing begins.
 It will be called on the main thread.
 
 该 block 将在异步绘制开始前被调用。
 
 注意它将在主线程中调用。
 
 block param layer:  The layer.
 */
@property (nullable, nonatomic, copy) void (^willDisplay)(CALayer *layer);

/**
 This block is called to draw the layer's contents.
 
 调用该 block 是为了绘制图层的内容。
 
 @discussion This block may be called on main thread or background thread,
 so is should be thread-safe.
 
 @discussion 该代码块可能会在主线程或后台线程上调用，因此应该是线程安全的。
 
 block param context:      A new bitmap content created by layer. 由图层创建的新位图内容。
 block param size:         The content size (typically same as layer's bound size). 内容大小（通常与图层的 bouns
 大小相同）。 block param isCancelled:  If this block returns `YES`, the method should cancel the drawing process and
 return as quickly as possible. 如果此 block 返回 `YES`，则该方法应取消绘图过程并尽快返回。
 */
@property (nullable, nonatomic, copy) void (^display)(CGContextRef context, CGSize size, BOOL (^isCancelled)(void));

/**
 This block will be called after the asynchronous drawing finished.
 It will be called on the main thread.
 
 异步绘制完成后，将调用该 block。它将在主线程中调用。
 
 block param layer:  The layer.
 block param finished:  If the draw process is cancelled, it's `NO`, otherwise it's `YES`.
 如果绘制过程被取消，则为`NO`，否则为`YES`。
 */
@property (nullable, nonatomic, copy) void (^didDisplay)(CALayer *layer, BOOL finished);

@end

NS_ASSUME_NONNULL_END
