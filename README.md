# 🕹️ Cub3D

Bem-vindo ao **Cub3D** — um projeto de raycasting inspirado no clássico **Wolfenstein 3D**. Este projeto foi desenvolvido como parte do currículo da 42 School, com o objetivo de criar um motor gráfico 3D simples a partir de uma visão em primeira pessoa, utilizando apenas a biblioteca **MiniLibX**.

## 📌 Descrição

O Cub3D renderiza um mundo 3D a partir de um mapa 2D usando a técnica de **raycasting**. O jogador pode se mover e rotacionar pela cena, com paredes texturizadas e sprites.

### 🎨 Funcionalidades:
- Renderização em primeira pessoa com Raycasting
- Mapeamento de texturas nas paredes
- Controle de movimento (andar, girar)
- Detecção de colisão com paredes
- Suporte a sprites (objetos na cena)
- Leitura de mapas a partir de arquivos `.cub`
- Tela inicializada com **MiniLibX**

## 🛠️ Como Compilar

Certifique-se de ter a **MiniLibX** instalada.

```bash
make
```

Para limpar arquivos objeto:
```bash
make clean
```

Para limpar tudo (incluindo o executável):
```bash
make fclean
```

Para recompilar tudo do zero:
```bash
make re
```

## ▶️ Como Executar

```bash
./cub3D mapas/mapa.cub
```

## 📁 Estrutura de Pastas

```
Cub3D/
├── includes/
│   └── cub3d.h
├── srcs/
│   ├── main.c
│   ├── parsing/
│   ├── raycasting/
│   ├── rendering/
│   └── utils/
├── mapas/
│   └── mapa.cub
├── textures/
│   └── parede.xpm
├── Makefile
└── README.md
```

## 📜 Formato do Arquivo `.cub`

Um arquivo `.cub` define:
- Resolução da janela
- Caminhos para as texturas
- Cores do chão e teto
- Mapa com `1` para paredes, `0` para espaços livres e `N`, `S`, `E`, `W` para a posição e direção inicial do jogador.

Exemplo:

```
R 1024 768
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
1000N1
100001
111111
```

## 🎮 Controles

| Tecla         | Ação                 |
|:--------------|:--------------------|
| `W`           | Andar para frente     |
| `S`           | Andar para trás       |
| `A`           | Mover para a esquerda |
| `D`           | Mover para a direita  |
| `Seta Esquerda` | Girar à esquerda     |
| `Seta Direita` | Girar à direita       |
| `ESC`         | Sair do jogo          |

## 📚 Créditos

Projeto desenvolvido por **mefranci e gkiala** como parte do programa **42 School**.

---

Se quiser, posso adaptar com mais informações específicas do seu projeto — quer? Se puder me passar o nome dos arquivos, ou como você organizou as funções, fica ainda mais personalizado!
