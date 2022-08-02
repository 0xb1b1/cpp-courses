FROM debian:stable-slim AS build

ENV CMAKE_CXX_COMPILER g++
RUN apt-get update -y && apt-get install -y gcc g++ cmake make
WORKDIR /usr/src
COPY . .
RUN cmake -S /usr/src -B /usr/build
RUN cd /usr/build && make


FROM scratch AS bin
COPY --from=build /usr/build /

# Run docker build --target bin --output build/ .
# Reference: https://www.docker.com/blog/containerize-your-go-developer-environment-part-1/
