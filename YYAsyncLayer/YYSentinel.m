//
//  YYSentinel.m
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 15/4/13.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import "YYSentinel.h"
#import <stdatomic.h>

@implementation YYSentinel {
    atomic_int _value;
}

- (int32_t)value {
    return _value;
}

- (int32_t)increase {
  return atomic_fetch_add(&_value, 1);
}

@end
