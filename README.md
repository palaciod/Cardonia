# Cardonia

A fantasy role-playing game built with Unreal Engine 5.4 featuring multi-species characters, extensive animal systems, and immersive world interaction mechanics.

## Game Overview

Cardonia is an ambitious fantasy RPG that emphasizes character diversity, wildlife interaction, and a rich inventory system. Players can explore a world populated by various species and engage with an extensive ecosystem of animals and collectible items.

## Key Features

### Multi-Species Character System
- **Human Variants**: Multiple subtypes including Giants, Dwarfs, Valtheri, Syvaris, and Adari
- **Human Ethnicities**: Anglo-Saxon, Nordic, Germanic, Celtic, Slavic, Latin, Greek, Middle Eastern, Asian, Mestizo, African, and Mulatto
- **Elf Subtypes**: High Elves, Wood Elves, Dark Elves, Snow Elves, Bloodwood Elves, and Drow
- **Other Races**: Orcs, Beasts, and various Animal species

### Advanced Animal Systems
- **Animal Categories**: Land, Aquatic, and Aerial animals
- **Extensive Animal Library**: Wolves, Lions, Deer, Foxes, Pigs, Crows, Zebras, and more
- **Realistic Animations**: Breathing, movement, attack, and interaction animations
- **Animal Behavior**: Complex AI and interaction systems

### Inventory & Collection System
- **Item Properties**: Weight, value, and visual representation
- **Interactive Collectibles**: Grab and store items throughout the world
- **Inventory Management**: Organized storage and item handling
- **Equipment System**: Character customization and gear management

### Combat & Interaction
- **Combat Mechanics**: Attack systems with damage calculations
- **Health Management**: Character health and damage systems
- **Interactive World**: Interface-based interaction with objects and NPCs
- **Character Abilities**: Species-specific traits and capabilities

## Technical Specifications

- **Engine**: Unreal Engine 5.4
- **Programming Languages**: C++ with Blueprint integration
- **Platform**: Windows (with potential for cross-platform expansion)
- **Architecture**: Component-based character system with interface-driven interactions

### Plugins & Assets
- **Character Control Rigs**: Advanced character animation systems
- **Substance Integration**: High-quality material workflows
- **USD Importer**: Industry-standard asset pipeline support
- **RLPlugin**: Enhanced character creation tools
- **Professional Animal Packs**: African Animals Pack, Animal Variety Pack

## Project Structure

```
Cardonia/
├── Source/Cardonia/           # C++ source code
│   ├── BaseCharacter.*        # Core character functionality
│   ├── Species.*              # Species definition system
│   ├── InventoryComponent.*   # Inventory management
│   ├── InventoryItem.*        # Item definitions
│   └── Collectible.*          # Collectible object system
├── Content/                   # Game assets
│   ├── Blueprints/           # Blueprint classes
│   ├── Animations/           # Character and animal animations
│   ├── AfricanAnimalsPack/   # African animal assets
│   ├── AnimalVarietyPack/    # Variety animal assets
│   ├── Characters/           # Character models and rigs
│   ├── UI/                   # User interface elements
│   └── Levels/               # Game levels and maps
├── Config/                   # Project configuration files
└── Plugins/                  # Third-party plugins
```

## Getting Started

### Prerequisites
- Unreal Engine 5.4
- Visual Studio 2022 (for C++ development)
- Git (for version control)

### Setup Instructions
1. Clone the repository:
   ```bash
   git clone https://github.com/palaciod/Cardonia.git
   ```

2. Navigate to the project directory:
   ```bash
   cd Cardonia
   ```

3. Right-click on `Cardonia.uproject` and select "Generate Visual Studio project files"

4. Open `Cardonia.sln` in Visual Studio

5. Build the project (Build → Build Solution)

6. Launch the project by opening `Cardonia.uproject` with Unreal Engine 5.4

### First Run
- The project includes sample content and character blueprints
- Explore the various animal demonstrations in the AnimalVarietyPack and AfricanAnimalsPack
- Test character interactions and inventory systems in the provided levels

## 🎯 Development Roadmap

### Current Features
- ✅ Multi-species character system
- ✅ Inventory and collection mechanics
- ✅ Animal integration and animations
- ✅ Basic combat system
- ✅ Interactive world objects

### Planned Features
- 🔄 Advanced AI behavior systems
- 🔄 Expanded combat mechanics
- 🔄 Quest and dialogue systems
- 🔄 Multiplayer support
- 🔄 Advanced crafting system

## 🤝 Contributing

We welcome contributions to Cardonia! Please follow these guidelines:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

### Code Style
- Follow Unreal Engine C++ coding standards
- Use descriptive variable and function names
- Comment complex systems and algorithms
- Maintain Blueprint organization and naming conventions

## 📋 System Requirements

### Minimum Requirements
- **OS**: Windows 10 64-bit
- **Processor**: Intel Core i5-8400 / AMD Ryzen 5 2600
- **Memory**: 16 GB RAM
- **Graphics**: NVIDIA GTX 1060 / AMD RX 580
- **DirectX**: Version 12
- **Storage**: 50 GB available space

### Recommended Requirements
- **OS**: Windows 11 64-bit
- **Processor**: Intel Core i7-10700K / AMD Ryzen 7 3700X
- **Memory**: 32 GB RAM
- **Graphics**: NVIDIA RTX 3070 / AMD RX 6700 XT
- **DirectX**: Version 12
- **Storage**: 50 GB SSD space

## 📄 License

This project is licensed under the MIT License - see the [LICENSE.txt](LICENSE.txt) file for details.

## Contact

- **Developer**: Daniel Palacio
- **Repository**: [https://github.com/palaciod/Cardonia](https://github.com/palaciod/Cardonia)
- **Issues**: [Project Issues](https://github.com/palaciod/Cardonia/issues)

---

*Cardonia - Where fantasy comes alive through diverse characters and immersive wildlife interactions.*
