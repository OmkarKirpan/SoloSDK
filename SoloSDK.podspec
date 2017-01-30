Pod::Spec.new do |s|
  s.name             = 'SoloSDK'
  s.version         = '0.0.1'
  s.platform     = :ios, ‘8.1’
  s.homepage         = 'http://www.tipit.tv'
  s.authors         = { 'tipitltd' => 'accounts@tipit.tv' }
  s.license         =  { :type => 'MIT' }
  s.summary         = 'A cocoa pod containing the Solo framework.'
  s.source           = { :git => 'https://github.com/tipitltd/SoloSDK.git', :tag => '0.0.1' }
  s.frameworks = 'Solo'
  s.vendored_frameworks = 'Solo.framework'
end
