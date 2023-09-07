#!/bin/bash

VOLUMES="-v $(pwd)/logs:/home/me/logs"

OPTIONS="--network bridge --cap-add=SYS_PTRACE --security-opt seccomp=unconfined --env-file=ports.env"

PORTS="-p:8999:8999"

CONTAINERIMAGE="cpp-microservice"
CONTAINERTAG="1.0.0"

case "$1" in
    -b|--build)
        docker build --no-cache -t $CONTAINERIMAGE/$CONTAINERTAG .
        ;;

    -u|--update)
        docker build -t $CONTAINERIMAGE/$CONTAINERTAG .
        ;;

    -d|--delete)
        docker rmi -f $CONTAINERIMAGE/$CONTAINERTAG
        ;;

    -r|--run)
        docker run -d -it --rm=true $VOLUMES $PORTS $OPTIONS $CONTAINERIMAGE/$CONTAINERTAG
        ;;

    -x|--exit)
        docker stop $(docker ps -q --filter ancestor=$CONTAINERIMAGE/$CONTAINERTAG )
        ;;

    -s|--shell)
        mkdir -p logs
        docker run -it --rm=true $VOLUMES $PORTS $OPTIONS $CONTAINERIMAGE/$CONTAINERTAG /bin/bash
        ;;

    *)
        echo $"Usage: $0 { build | update | delete | run | exit | shell }"
        exit 1
esac
