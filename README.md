# ext-include-logger

## How to build

```sh
phpize
./configure
make
```

## Run

```sh
php -d extension=module/include_logger.so
```

This will output:

```sh
Including file: Standard input code
```

## Test

```sh
$ make test
# or
php run-tests.php -d extension=modules/include_logger.so tests
```
