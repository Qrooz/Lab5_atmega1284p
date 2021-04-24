tests = [ {'description': 'PINA: 0x03 => PORTC: 0x70',
    'steps': [ {'inputs': [('PINA',0x03)], 'iterations': 5 } ],
    'expected': [('PORTC',0x70)],
    },
    {'description': 'PINA: 0x0F => PORTC: 0x3F',
    'steps': [ {'inputs': [('PINA',0x0F)], 'iterations': 5 } ],
    'expected': [('PORTC',0x3F)],
    },
    {'description': 'PINA: 0x0A => PORTC: 0x3E',
    'steps': [ {'inputs': [('PINA',0x0A)], 'iterations': 5 } ],
    'expected': [('PORTC',0x3E)],
    },
    ]
#watch = ['PORTC']
