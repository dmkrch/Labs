FROM python:3.8-alpine

RUN mkdir -p /usr/src/app/
WORKDIR /usr/src/app/

COPY . /usr/src/app/

ENTRYPOINT [ "python", "GetSize.py" ]