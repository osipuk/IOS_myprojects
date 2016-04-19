//
//  NSString+Crypto.h
//  AppstoreVN
//
//  Created by Anh Toan on 11/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonDigest.h>

@interface NSString (Crypto)

/**
 * Computes a SHA256 hash of the string.
 * @return A SHA256 hash in hexadecimal representation (64 chars)
 */
- (NSString*) SHA256;

@end
