//
//  YYTransaction.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 15/4/18.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 YYTransaction let you perform a selector once before current runloop sleep.
 
 YYTransaction 可让您在当前运行循环休眠前执行一次 selector。
 */
@interface YYTransaction : NSObject

/**
 Creates and returns a transaction with a specified target and selector.
 
 创建并返回一个具有指定 target 和 selector 的事务。
 
 @param target    A specified target, the target is retained until runloop end. 指定目标，该目标将保留到运行循环结束。
 @param selector  A selector for target. target 的 selector。
 
 @return A new transaction, or nil if an error occurs. 一个新事务，如果出错则为 nil。
 */
+ (YYTransaction *)transactionWithTarget:(id)target selector:(SEL)selector;

/**
 Commit the trancaction to main runloop.
 
 向 main runloop 提交事务。
 
 @discussion It will perform the selector on the target once before main runloop's
 current loop sleep. If the same transaction (same target and same selector) has
 already commit to runloop in this loop, this method do nothing.
 它将在 main runloop 当前循环休眠前对目标执行一次选择器操作。如果同一事务（同一目标和同一选择器）已在此循环中提交给
 runloop，则此方法不会执行任何操作。
 */
- (void)commit;

@end

NS_ASSUME_NONNULL_END
