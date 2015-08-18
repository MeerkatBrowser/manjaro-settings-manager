# This is meant to be built using 'buildpkg' from 'manjaro-tools'
# Maintainer : Ramon Buldo <ramon@manjaro.org>
pkgname=kcm-msm
pkgver=0.0.1
pkgrel=1
_pkgver=0.0.1
pkgdesc="Manjaro Linux System Settings Tool (KCM for Plasma 5)"
arch=('i686' 'x86_64')
url="https://github.com/manjaro/manjaro-settings-manager"
license=("GPL")
depends=('icu' 'qt5-base' 'qt5-webengine' 'hwinfo' 'kitemmodels' 'kauth' 
         'kconfigwidgets' 'kcoreaddons' 'kcmutils')
makedepends=('git' 'extra-cmake-modules' 'kdoctools' 'qt5-tools')
source=(git+$url.git)
sha256sums=(SKIP)

pkgver() {
	cd "$srcdir/manjaro-settings-manager"
	_git=".r$(git rev-list --count HEAD).$(git rev-parse --short HEAD)"
	echo -e "${_pkgver}${_git}"
}

build() {
  cd "$srcdir/manjaro-settings-manager"
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
  cd "$srcdir/manjaro-settings-manager/build"
  make DESTDIR=${pkgdir} install
}
