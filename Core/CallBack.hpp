//
//  CallBack.hpp
//  OpenGLGame
//
//  Created by YouTooLife on 9/14/18.
//  Copyright © 2018 YouTooLife. All rights reserved.
//

#ifndef CallBack_hpp
#define CallBack_hpp

class CallBack
{
public:
    virtual void callBack();
};

class KeyCreated
{
public:
    static void callBack(CallBack call)
    {
        call.callBack();
    }
};

#endif /* CallBack_hpp */
