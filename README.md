# Minitalk [![42](https://i.imgur.com/9NXfcit.jpg)](i.imgur.com/9NXfcit.jpg)

project [42](https://www.42urduliz.com/) school

## Description

This project is about creating a small data exchange program using UNIX signals (SIGUSR1 and SIGUSR2).

## Usage

### Server

```bash
$> make
$> ./server
```

### Client

```bash
$> ./client [PID] [message]
```

## Example

```bash
$> ./server
$> ./client 12345 "Hello World!"
$> Hello World!
```
