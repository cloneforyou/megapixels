project('megapixels', 'c')
gtkdep = dependency('gtk+-3.0')
gldep = dependency('epoxy')
executable('megapixels', 'main.c', 'ini.c', 'bayer.c', dependencies : [gtkdep, gldep], install : true)

install_data(['camera.glade', 'camera.css'],
             install_dir : get_option('datadir') / 'megapixels/ui')

install_data(['org.postmarketos.Megapixels.desktop'],
             install_dir : get_option('datadir') / 'applications')

install_data('org.postmarketos.Megapixels.svg',
  install_dir: join_paths(get_option('datadir'), 'icons/hicolor/scalable/apps')
)
