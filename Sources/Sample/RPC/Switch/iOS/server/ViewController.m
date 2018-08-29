#import "ViewController.h"
#import "CppInterface.h"
#import "SwitchServer-Swift.h"

@interface ViewController ()
{
    CppInterface* i;
}
@end

@implementation ViewController

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender{
    
    if([[segue identifier] isEqualToString:@"MyQRCodeIdentifier"]) {
        MyQRCodeViewController *vc = (MyQRCodeViewController*)segue.destinationViewController;
        vc.qrCodeString = @"This should be my Carrier address!";
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];
//    i = [[CppInterface alloc]init];
    
//    const int labelWidth = 300;
//    const int labelHeight = 100;
//    CGRect labelFrame = CGRectMake((self.view.frame.size.width - labelWidth) / 2,
//                                   (self.view.frame.size.height - labelHeight) / 2,
//                                   labelWidth, labelHeight);
//
//
//    UILabel *myLabel = [[UILabel alloc] initWithFrame:labelFrame];
//
//    myLabel.font = [UIFont boldSystemFontOfSize:30.0f];
//    myLabel.textAlignment =  NSTextAlignmentCenter;
//
//    myLabel.numberOfLines = 2;
//    myLabel.text = i.greeting;
//
//    [self.view addSubview:myLabel];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
