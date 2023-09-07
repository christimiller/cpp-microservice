FROM ubuntu

EXPOSE 8999

RUN apt-get update && apt-get install -y libboost-atomic-dev \
  libboost-thread-dev libboost-system-dev libboost-date-time-dev \
  libboost-serialization-dev libwebsocketpp-dev openssl libssl-dev \
  libcpprest-dev

RUN useradd -m -s /bin/bash me
USER me
WORKDIR /home/me

ENV USER=me
ENV PATH="/home/me/.local/bin:${PATH}"
ENV LOGDIR="/home/me/logs/"

COPY ./bin/cppsvc /home/me/cppsvc
CMD ["/home/me/cppsvc"]
