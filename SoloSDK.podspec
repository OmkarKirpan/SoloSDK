Pod::Spec.new do |s|
  s.name             = 'SoloSDK'
  s.version         = '6.1.1'
  s.platform     = :ios, '11.0'
  s.homepage         = 'https://camerai.co'
  s.authors         = { 'Camerai' => 'info@camerai.co' }
  s.license         =  { :type => 'MIT' }
  s.summary         = 'A cocoa pod containing the Solo framework.'
  s.source           = { :git => 'https://github.com/tipitltd/SoloSDK.git', :tag => '6.1.1' }
  s.frameworks = 'Solo'
  s.vendored_frameworks = 'Solo.framework'
end
