#import "CppInterface.h"

#include "Elastos.HelloCarDemo.h"

@implementation CppInterface

-(instancetype)init
{
    self = [super init];
    if (self) {
        AutoPtr<IHelloCar> myHelloCar;
        String name;
        CHelloCar::New((IHelloCar**)&myHelloCar);
        ECode ec = myHelloCar->Hello(&name);
        if(FAILED(ec)) {
            printf("CHelloCar::New() error! ec = %x\n\n", ec);
            return nullptr;
        }
        printf("Hello %s\n", name.string());
        _greeting = [NSString stringWithFormat:@"Hello iOS!\nHello %s!", name.string()];
    }
    return self;
}

@end
