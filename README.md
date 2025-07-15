# QMK Programmer Dvorak

## QMK Setup

```
python3 -m pip install qmk
```

```
qmk setup
```

## Keyboard Layout Installation

Create directory `programmer_dvorak` under `~/qmk_firmware/keyboards/hhkb/ansi/keymaps/` and move `keymap.c` into that directory. 

Compile: 

```
qmk compile -kb hhkb/ansi -km programmer_dvorak
```

Put your keyboard into bootloader mode. (For my keyboard with an 4pplet HHKB Pro 2 custom controller, the button is in the back where the switches used to be.)

Then, flash: 

```
qmk flash -kb hhkb/ansi -km programmer_dvorak
```