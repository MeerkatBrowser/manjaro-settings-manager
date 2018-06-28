# This is for local testing and only works if used in the root of the cloned repo (with makepkg)
# Maintainer : Ramon Buldo <ramon@manjaro.org>
pkgbase=namib-settings-manager
pkgname=('namib-settings-manager' 'namib-settings-manager-kcm' 
         'namib-settings-manager-notifier' 'namib-settings-manager-knotifier')
pkgver=0.5.4
pkgrel=14
pkgdesc="Namib settings manager module"
arch=('i686' 'x86_64')
url="https://github.com/meerkatbrowser/namib-settings-manager"
license=("GPL")
depends=('icu>=61.1' 'qt5-base>=5.9.1' 'hwinfo' 'kitemmodels' 'kauth' 
         'kcoreaddons' 'ckbcomp' 'xdg-utils')
optdepends=('namib-settings-manager-notifier: qt-based'
            'namib-settings-manager-knotifier: knotifications-based')
makedepends=('extra-cmake-modules' 'kdoctools' 'qt5-tools' 'knotifications' 
             'kconfigwidgets' 'kcmutils')
conflicts=('kcm-nsm')

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

package_namib-settings-manager() {
  cd ..
  cd build
  make DESTDIR=${pkgdir} install 
  rm -rf $pkgdir/usr/bin/msm_notifier
  rm -rf $pkgdir/usr/bin/msm_kde_notifier
  rm -rf $pkgdir/usr/lib/qt
  rm -rf $pkgdir/usr/share/kservices5
  rm -rf $pkgdir/usr/share/applications/msm_notifier_settings.desktop
  rm -rf $pkgdir/usr/share/applications/msm_kde_notifier_settings.desktop
  rm -rf $pkgdir/etc/xdg
}

package_namib-settings-manager-kcm() {
  pkgdesc="Namib Linux System Settings Tool (KCM for Plasma 5)"
  depends=('namib-settings-manager' 'kcmutils' 'kconfigwidgets')
  replaces=('kcm-nsm')
  cd ..
  cd build
  make DESTDIR=${pkgdir} install
  rm -rf $pkgdir/etc  
  rm -rf $pkgdir/usr/bin
  rm -rf $pkgdir/usr/lib/kauth
  rm -rf $pkgdir/usr/share/{applications,dbus-1,icons,polkit-1}
}

package_namib-settings-manager-notifier() {
  pkgdesc="Namib Linux System Settings Tool (Notifier)"
  depends=('Namib-settings-manager')
  provides=('namib-settings-manager-kde-notifier')
  conflicts=('namib-settings-manager-kde-notifier')
  cd ..
  cd build
  make DESTDIR=${pkgdir} install
  rm -rf $pkgdir/etc/dbus-1
  rm -rf $pkgdir/etc/xdg/autostart/msm_kde_notifier.desktop
  rm -rf $pkgdir/usr/lib/
  rm -rf $pkgdir/usr/share/{kservices5,dbus-1,icons,polkit-1}
  rm -rf $pkgdir/usr/share/applications/namib*
  rm -rf $pkgdir/usr/share/applications/msm_kde_notifier_settings.desktop
  rm -rf $pkgdir/usr/bin/namib*
  rm -rf $pkgdir/usr/bin/msm_kde_notifier
}

package_namib-settings-manager-knotifier() {
  pkgdesc="Namib Linux System Settings Tool (Notifier for Plasma 5)"
  depends=('namib-settings-manager' 'knotifications')
  conflicts=('namib-settings-manager-notifier')
  replaces=('namib-settings-manager-kde-notifier')
  cd ..
  cd build
  make DESTDIR=${pkgdir} install
  rm -rf $pkgdir/etc/dbus-1
  rm -rf $pkgdir/etc/xdg/autostart/msm_notifier.desktop
  rm -rf $pkgdir/usr/lib/
  rm -rf $pkgdir/usr/share/{kservices5,dbus-1,icons,polkit-1}
  rm -rf $pkgdir/usr/share/applications/namib*
  rm -rf $pkgdir/usr/share/applications/msm_notifier_settings.desktop
  rm -rf $pkgdir/usr/bin/namib*
  rm -rf $pkgdir/usr/bin/msm_notifier
} 
