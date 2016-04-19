/*
 * Copyright 2012 Appota
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

/// The error domain of all error codes returned by the Appota SDK
extern NSString *const AppotaSDKDomain;

extern NSString *const APInvalidOperationException;

// Appota SDK also raises exceptions the following common exceptions:
//  NSInvalidArgumentException

extern NSString *const APErrorGetSMSTopUp;

extern NSString *const APErrorTopupCard;

extern NSString *const APErrorGetSmartLinkTopUp;

extern NSString *const APErrorGetPaypalLinkTopUp;

extern NSString *const APErrorCheckTopUp;

extern NSString *const APErrorGetSMSInApp;

extern NSString *const APErrorInAppCard;

extern NSString *const APErrorGetSmartLinkInApp;

extern NSString *const APErrorGetPaypalLinkInApp;

extern NSString *const APErrorCheckInApp;