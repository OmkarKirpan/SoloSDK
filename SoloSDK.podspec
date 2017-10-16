Pod::Spec.new do |s|
  s.name             = 'SoloSDK'
  s.version         = '4.0.0'
  s.platform     = :ios, '10.0'
  s.homepage         = 'http://www.tipit.tv'
  s.authors         = { 'tipitltd' => 'accounts@tipit.tv' }
  s.license         =  { :type => 'MIT' }
  s.summary         = 'A cocoa pod containing the Solo framework.'
  s.source           = { :git => 'https://github.com/tipitltd/SoloSDK.git', :tag => '4.0.0' }
  s.frameworks = 'Solo'
  s.vendored_frameworks = 'Solo.framework'
end
