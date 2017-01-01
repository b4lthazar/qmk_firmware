To build and load:

1. Plug only the left keyboard in and reset it.

```
cd keyboards/ergodox
make infinity-b4lthazar-dfu-util
```

2. Plug only the right keyboard in and reset it.
```
make infinity-b4lthazar-dfu-util MASTER=right
```

