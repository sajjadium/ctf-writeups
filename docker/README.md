# Preparing the Docker

Architecture:   amd64, i386, arm32v7, arm64v8
Ubuntu Release: 16.04, 17.10, 18.04, 18.10

## Building the Image

```
./build-image.sh <Architecture> <Ubuntu Release>
```

## Creating the Container

### Linux

```
./create-container-linux.sh <Architecture> <Ubuntu Release>
```

### MacOS

```
./create-container-macos.sh <Architecture> <Ubuntu Release>
```

## Running the Container

### Linux

```
./run-container-linux.sh <Architecture> <Ubuntu Release>
```

### MacOS

```
./run-container-macos.sh <Architecture> <Ubuntu Release>
```

