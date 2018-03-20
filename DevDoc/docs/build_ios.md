# iOS Build Instructions(Experimental)

## Install homebrew（https://brew.sh/）

```
$ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

## Install cmake
```
$ brew install cmake
```

## Install Xcode
search in AppStore and install

## Check Xcode path

```
$ /usr/bin/xcode-select -print-path
```

if the result is not “/Applications/Xcode.app/Contents/Developer”，then 
```
$ sudo xcode-select --switch /Applications/Xcode.app
```

## Install simulator in Xcode

Xcode->Preferences->Components, install iOS 11.1 Simulator

## Build

```
$ cd Elastos.RT
$ source Setup/SetEnv.sh
```

select ios_simulator64 or ios_device 

```
$ emake
```
