//
//  KSString.c
//  LerningCPart1
//
//  Created by Serg Bla on 25.10.15.
//  Copyright © 2015 Serg Bla. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "KSString.h"
#include "KSMacros.h"

#pragma mark -
#pragma mark Initializations & Dealocation

void __KSStringDeallocate(KSString *object) {
    KSStringSetValue(object, NULL);
    
    __KSObjectDeallocate(object);
}


KSString *KSStringCreate(char *value) {
    KSString *object = KSObjectCreateOfType(KSString);
    KSStringSetValue(object, value);
    
    return object;
}

#pragma mark -
#pragma mark Accessors

char *KSStringValue(KSString *object) {
  return KSObjectGetter(object, _value, NULL);
}

void KSStringSetValue(KSString *object, char *value) {
    if (NULL == object && object->_value == value) {
        return;
    }
    
    if (NULL != object->_value) {
        free(object->_value);
        object->_value = NULL;
    }
    
    if (value) {
        char *copiedString = strdup(value);
        assert(NULL != copiedString);
        
        object->_value = copiedString;
    }
}
#pragma mark -
#pragma mark Public Implementations

size_t KSStringLength(KSString *object) {
    return strlen(KSStringValue(object));
}
