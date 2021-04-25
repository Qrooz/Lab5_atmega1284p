tests = [ 
    {
        'description': 'PINA: 0x00 => PORTB: 0x2A',
        'steps': [{'inputs': [('PINA', 0xFF)], 'iterations': 1}],
        'expected': [('PORTB',0x2A)],
    },
    {
        'description': 'PINA: 0x00,0x01 => PORTB: 0x15',
        'steps': [
            {'inputs': [('PINA', 0xFF)], 'iterations': 1},
            {'inputs': [('PINA', 0xFE)], 'iterations': 1},
            ],
        'expected': [('PORTB',0x15)],
    },
    {
        'description': 'PINA: 0x00,0x01,0x00,0x01 => PORTB: 0x3F',
        'steps': [
            {'inputs': [('PINA', 0xFF)], 'iterations': 1},
            {'inputs': [('PINA', 0xFE)], 'iterations': 1},
            ],
        'expected': [('PORTB',0x3F)],
    },
    {
        'description': 'PINA: 0x00,0x01,0x00,0x01,0x00,0x01 => PORTB: 0x2A',
        'steps': [
            {'inputs': [('PINA', 0xFF)], 'iterations': 1},
            {'inputs': [('PINA', 0xFE)], 'iterations': 1},
        ],
        'expected': [('PORTB',0x2A)],
    },
    ]
watch = ['LED_State', 'PORTB']
