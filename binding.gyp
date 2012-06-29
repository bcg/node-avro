{
  'targets': [
    {
      'target_name': 'navro',
      'sources': [ 'src/addon.cc', 'src/navro.cc' ],
      'cflags_cc!': ['-fno-rtti', '-fno-exceptions'],
      'conditions': [
        ['OS=="mac"', {
          'include_dirs': ['/usr/local/include/boost'],
          'link_settings': {
            'libraries': ['/usr/local/lib/libavrocpp.dylib'],
          },
          'xcode_settings': {
            'GCC_ENABLE_CPP_RTTI': 'YES',
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
          }
        }],
      ],
    }
  ]
}
