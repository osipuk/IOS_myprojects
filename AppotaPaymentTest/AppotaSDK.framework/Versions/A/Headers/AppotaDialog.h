//
//  AppotaDialog.h
//  AppotaExample2
//
//  Created by tuent on 5/10/13.
//
//

#import <UIKit/UIKit.h>
@protocol AppotaDialogDelegate;


@interface AppotaDialog : UIView <UIWebViewDelegate, UIScrollViewDelegate> {
    id<AppotaDialogDelegate> _delegate;
    NSURLRequest *_serverRequest;
    NSURL* _serverURL;
    UIWebView* _webView;
    UIActivityIndicatorView* _spinner;
    UIImageView *_loadingView;
    
    UIButton* _closeButton;
    UIInterfaceOrientation _orientation;
    BOOL _showingKeyboard;
    BOOL _isViewInvisible;
    
    CGFloat kPadding;
    CGFloat kBorderWidth;

    
    // Ensures that UI elements behind the dialog are disabled.
    UIView* _modalBackgroundView;
}
/**
 * The delegate.
 */
@property(nonatomic, strong) id<AppotaDialogDelegate> delegate;

- (id)initWithURLRequest:(NSURLRequest *) serverRequest
                  params: (NSMutableDictionary *) params
         isViewInvisible: (BOOL)isViewInvisible
                delegate: (id <AppotaDialogDelegate>) delegate;
- (id)initWithURL: (NSString *) serverURL
           params: (NSMutableDictionary *) params
  isViewInvisible: (BOOL)isViewInvisible
         delegate: (id <AppotaDialogDelegate>) delegate;
- (void)show;
- (void) showWithAnimation:(BOOL) animation;
- (void)cancel;
- (void) showSpinner;
- (void)hideSpinner;
- (BOOL) isAjaxRequest:(NSURLRequest*) request;
- (BOOL) hasWebLoadingURL:(NSString*) urlString;
- (void) updateWebOrientation;
- (void) hideOrShowViewWithState:(BOOL) hideState;
@end

///////////////////////////////////////////////////////////////////////////////////////////////////

/*
 *Your application should implement this delegate
 */
@protocol AppotaDialogDelegate <NSObject>
- (void) closeWebView;
@optional

- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request
 navigationType:(UIWebViewNavigationType)navigationType;


/**
 * Called when the dialog succeeds and is about to be dismissed.
 */
- (void)dialogDidComplete:(AppotaDialog *)dialog;

/**
 * Called when the dialog succeeds with a returning url.
 */
- (void)dialogCompleteWithUrl:(NSURL *)url;

/**
 * Called when the dialog get canceled by the user.
 */
- (void)dialogDidNotCompleteWithUrl:(NSURL *)url;

/**
 * Called when the dialog is cancelled and is about to be dismissed.
 */
- (void)dialogDidNotComplete:(AppotaDialog *)dialog;

/**
 * Called when dialog failed to load due to an error.
 */
- (void)dialog:(AppotaDialog*)dialog didFailWithError:(NSError *)error;

/**
 * Asks if a link touched by a user should be opened in an external browser.
 *
 * If a user touches a link, the default behavior is to open the link in the Safari browser,
 * which will cause your app to quit.  You may want to prevent this from happening, open the link
 * in your own internal browser, or perhaps warn the user that they are about to leave your app.
 * If so, implement this method on your delegate and return NO.  If you warn the user, you
 * should hold onto the URL and once you have received their acknowledgement open the URL yourself
 * using [[UIApplication sharedApplication] openURL:].
 */
- (BOOL)dialog:(AppotaDialog*)dialog shouldOpenURLInExternalBrowser:(NSURL *)url;

- (void)dismiss:(BOOL)animated;

@end
