//
//  KSUserCell.m
//  KSProjectUI
//
//  Created by Serg Bla on 09.02.16.
//  Copyright © 2016 Serg Kostiuk. All rights reserved.
//

#import "KSUserCell.h"

#import "KSUser.h"

@interface KSUserCell ()

- (void)fillWithModel:(KSUser *)user;

@end

@implementation KSUserCell

#pragma mark - 
#pragma mark Accessors

- (void)setUser:(KSUser *)user {
    if (_user != user) {
        [_user removeObserver:self];
        _user = user;
        [_user addObserver:self];
        
        [self fillWithModel:user];
    }
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];
    
    self.accessoryType = (selected) ? UITableViewCellAccessoryCheckmark : UITableViewCellAccessoryNone;
}

#pragma mark -
#pragma mark Private

- (void)fillWithModel:(KSUser *)user {
    self.label.text = user.name;
    self.contentImageView.image = user.image;
}

@end
