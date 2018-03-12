#import "CppInterface.h"

@interface CppInterface ()
{
}
@end

#include <_Elastos.HelloCarDemo.h>
using namespace Elastos::HelloCarDemo;

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
            return;
        }
        printf("Hello %s\n", name.string());
    }
    return self;
}

@end
