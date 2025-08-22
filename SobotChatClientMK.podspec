Pod::Spec.new do |s|


s.name         = "SobotChatClientMK"
s.version      = "4.2.7.2"
s.summary      = "SobotSDK V6 MK"

s.description      = <<-DESC
  It is marquee view used on iOS, which implement by Objective-C 406 x86_64 arm64.
DESC

s.homepage         = "https://github.com/ZCSDK/SobotChatClientMK.git"
s.license          = 'MIT'
s.author           = { 'zhangxy' => 'app_dev@sobot.com' }
s.source           = { :git => "https://github.com/ZCSDK/SobotChatClientMK.git", :tag => s.version.to_s }
# s.social_media_url = 'https://twitter.com/NAME'

s.platform     = :ios, '9.0'
s.requires_arc = true

s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }

s.frameworks =  "AudioToolbox","AssetsLibrary","SystemConfiguration","AVFoundation","MobileCoreServices","WebKit"
#s.library   = 'z.1.2.5'

# s.resource  = "icon.png"
s.resources = 'SobotKit.bundle'
s.ios.vendored_frameworks = 'SobotKit.framework','SobotChatClient.framework','SobotCommon.framework'

# s.preserve_paths = "FilesToSave", "MoreFilesToSave"

end
