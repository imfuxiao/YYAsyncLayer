//
//  YYSentinel.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 15/4/13.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 YYSentinel is a thread safe incrementing counter.
 It may be used in some multi-threaded situation.
 
 YYSentinel 是一个线程安全递增计数器。它可用于某些多线程情况。
 */
@interface YYSentinel : NSObject

/// Returns the current value of the counter.
/// 返回计数器的当前值。
@property (readonly) int32_t value;

/// Increase the value atomically.
/// 以原子方式增加数值
///
/// @return The new value.
- (int32_t)increase;

@end

NS_ASSUME_NONNULL_END
