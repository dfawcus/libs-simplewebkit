/* simplewebkit
   WebDataSource.h

   Copyright (C) 2007-2010 Free Software Foundation, Inc.

   Author: Dr. H. Nikolaus Schaller

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this library; see the file COPYING.LIB.
   If not, write to the Free Software Foundation,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#import <Foundation/Foundation.h>
#import <WebKit/WebDocument.h>

@class WebArchive;
@class WebFrame;
@class WebResource;

@interface WebDataSource : NSObject
{
	NSURLConnection *_connection;								// our connection while we are loading
	id <WebDocumentRepresentation> _representation;	// representation - created as soon as header has been received
	NSURLRequest *_initial;
	NSMutableURLRequest *_request;
	NSURLResponse *_response;
	NSMutableData *_loadedData;
	NSMutableDictionary *_subresources;					// WebResource objects
	NSMutableDictionary *_subdatasources;				// the WebDataSource objects that are still loading
	WebDataSource *_parent;											// if we are a subresource
	id _ident;																	// identifier for WebResourceLoadDelegate
	WebFrame *_webFrame;
	NSURL *_unreachableURL;
	BOOL _finishedLoading;
}

- (void) addSubresource:(WebResource *) res;
- (NSData *) data;
- (NSURLRequest *) initialRequest;
- (id) initWithRequest:(NSURLRequest *) request;
- (BOOL) isLoading;
- (WebResource *) mainResource;
- (NSString *) pageTitle;
- (id <WebDocumentRepresentation>) representation;
- (NSMutableURLRequest *) request;
- (NSURLResponse *) response;
- (NSArray *) subresources;
- (WebResource *) subresourceForURL:(NSURL *) url;
- (NSString *) textEncodingName;
- (NSURL *) unreachableURL;
- (WebArchive *) webArchive;
- (WebFrame *) webFrame;

@end
