# This is for local testing and only works if used in the root of the cloned repo (with makepkg)
# Maintainer : Ramon Buldo <ramon@manjaro.org>

pkgname=kcm-nsm
pkgver=0.4.95
pkgrel=1
pkgdesc="Namib settings manager module"
arch=('i686' 'x86_64')
url="https://github.com/meerkatbrowser/namib-settings-manager"
license=("GPL")
depends=('icu' 'qt5-base' 'hwinfo' 'kitemmodels' 'kauth' 
         'kconfigwidgets' 'kcoreaddons' 'kcmutils' 'ckbcomp'
         'knotifications' 'xdg-utils')
makedepends=('git' 'extra-cmake-modules' 'kdoctools' 'qt5-tools')
conflicts=('manjaro-settings-manager' 'manjaro-settings-manager-kcm' 'manjaro-settings-manager-knotifier' 'manjaro-settings-manager-notifier')
provides=("manjaro-settings-manager" 'manjaro-settings-manager-kcm' 'manjaro-settings-manager-knotifier' 'manjaro-settings-manager-notifier')

build() {
  cd ..
  mkdir -p build
  cd build
  cmake ../ \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DLIB_INSTALL_DIR=lib \
    -DKDE_INSTALL_USE_QT_SYS_PATHS=ON \
    -DSYSCONF_INSTALL_DIR=/etc
  make
}

package() {
  cd ..
  cd build
  make DESTDIR=${pkgdir} install
}
