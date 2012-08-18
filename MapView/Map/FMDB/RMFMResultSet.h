#import <Foundation/Foundation.h>
#import "sqlite3.h"

@class RMFMDatabase;
@class FMStatement;

@interface RMFMResultSet : NSObject {
    RMFMDatabase *parentDB;
    FMStatement *statement;
    
    NSString *query;
    NSMutableDictionary *columnNameToIndexMap;
    BOOL columnNamesSetup;
}


+ (id) resultSetWithStatement:(FMStatement *)statement usingParentDatabase:(RMFMDatabase *)aDB;

- (void) close;

- (NSString *)query;
- (void)setQuery:(NSString *)value;

- (FMStatement *)statement;
- (void)setStatement:(FMStatement *)value;

- (void)setParentDB:(RMFMDatabase *)newDb;

- (BOOL) next;
- (BOOL) hasAnotherRow;

- (int) columnIndexForName:(NSString*)columnName;
- (NSString*) columnNameForIndex:(int)columnIdx;

- (int) intForColumn:(NSString*)columnName;
- (int) intForColumnIndex:(int)columnIdx;

- (long) longForColumn:(NSString*)columnName;
- (long) longForColumnIndex:(int)columnIdx;

- (long long int) longLongIntForColumn:(NSString*)columnName;
- (long long int) longLongIntForColumnIndex:(int)columnIdx;

- (BOOL) boolForColumn:(NSString*)columnName;
- (BOOL) boolForColumnIndex:(int)columnIdx;

- (double) doubleForColumn:(NSString*)columnName;
- (double) doubleForColumnIndex:(int)columnIdx;

- (NSString*) stringForColumn:(NSString*)columnName;
- (NSString*) stringForColumnIndex:(int)columnIdx;

- (NSDate*) dateForColumn:(NSString*)columnName;
- (NSDate*) dateForColumnIndex:(int)columnIdx;

- (NSData*) dataForColumn:(NSString*)columnName;
- (NSData*) dataForColumnIndex:(int)columnIdx;

- (const unsigned char *) UTF8StringForColumnIndex:(int)columnIdx;
- (const unsigned char *) UTF8StringForColumnName:(NSString*)columnName;

/*
If you are going to use this data after you iterate over the next row, or after you close the
result set, make sure to make a copy of the data first (or just use dataForColumn:/dataForColumnIndex:)
If you don't, you're going to be in a world of hurt when you try and use the data.
*/
- (NSData*) dataNoCopyForColumn:(NSString*)columnName;
- (NSData*) dataNoCopyForColumnIndex:(int)columnIdx;

- (BOOL) columnIndexIsNull:(int)columnIdx;
- (BOOL) columnIsNull:(NSString*)columnName;

- (void) kvcMagic:(id)object;

@end
