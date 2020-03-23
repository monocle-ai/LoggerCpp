FROM gcc:9.2

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends cmake=3.10.3 libgtest-dev libboost-test-dev && rm -rf /var/lib/apt/lists/*

CMD ["cmake"]