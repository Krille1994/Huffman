#include <bitset>


struct Node
{
    char value;
	u8_t child0;
	u8_t child1;
    Node(char c):value(c);
    Node(n0,n1):child0(n0), child1(n1);
};inline std::vector<Node> v_tree {Node('@'),Node('^'),Node(0,1),Node('#'),Node(2,3),Node('''),Node('\'),Node(4,5),Node('Z'),Node('G'),Node('`'),Node('9'),Node('%'),Node('7'),Node('q'),Node('J'),Node(6,7),Node('Q'),Node('4'),Node('6'),Node('3'),Node('8'),Node(8,9),Node('K'),Node('X'),Node(10,11),Node(12,13),Node('Y'),Node('U'),Node(14,15),Node(16,17),Node('$'),Node(18,19),Node('j'),Node(20,21),Node('N'),Node(22,23),Node('H'),Node('W'),Node('5'),Node(24,25),Node('B'),Node('V'),Node(26,27),Node('F'),Node(28,29),Node('I'),Node('z'),Node('<'),Node(30,31),Node('E'),Node('R'),Node('/'),Node('L'),Node(32,33),Node('*'),Node(34,35),Node('2'),Node('T'),Node('A'),Node('O'),Node(36,37),Node('C'),Node(38,39),Node('D'),Node('>'),Node(40,41),Node(42,43),Node('P'),Node('S'),Node(44,45),Node(46,47),Node(48,49),Node('?'),Node('k'),Node(50,51),Node(52,53),Node('1'),Node('M'),Node(54,55),Node('w'),Node('-'),Node(56,57),Node(58,59),Node('!'),Node(60,61),Node(62,63),Node(64,65),Node(66,67),Node('v'),Node(68,69),Node('|'),Node('['),Node(']'),Node('+'),Node(70,71),Node('y'),Node(72,73),Node('_'),Node(74,75),Node(76,77),Node('0'),Node(78,79),Node(80,81),Node('&'),Node(82,83),Node('b'),Node(84,85),Node('x'),Node(86,87),Node('m'),Node(88,89),Node(';'),Node(90,91),Node(92,93),Node(94,95),Node('}'),Node('{'),Node(96,97),Node('"'),Node('p'),Node('g'),Node(98,99),Node('f'),Node(' '),Node(100,101),Node(102,103),Node(104,105),Node('u'),Node(':'),Node(106,107),Node(108,109),Node('d'),Node(110,111),Node(112,113),Node('c'),Node(114,115),Node(116,117),Node(118,119),Node(120,121),Node('h'),Node(122,123),Node('l'),Node(124,125),Node(126,127),Node(')'),Node('('),Node(128,129),Node('='),Node(130,131),Node('r'),Node('.'),Node(132,133),Node('a'),Node('o'),Node(134,135),Node(','),Node(136,137),Node('n'),Node(138,139),Node('s'),Node(140,141),Node(142,143),Node('i'),Node(144,145),Node(146,147),Node(148,149),Node('e'),Node(150,151),Node(152,153),Node(154,155),Node(156,157),Node('t'),Node(158,159),Node(160,161),Node(162,163),Node(164,165),Node(166,167),Node(168,169),Node(170,171),Node(172,173),Node(174,175),Node(176,177),Node(178,179),Node(180,181),Node(182,183),Node(184,185),};

inline u8_t root_index 186;
