# Airith 1.0 - AI Blueprint Assistant for Unreal Engine 5.7

Airith is an AI-powered plugin for Unreal Engine 5.7 to help you create, modify, and understand Blueprints through natural language prompts.

## Features

- **Natural Language Blueprint Creation**: Describe what you want, and Aerith creates Blueprints for you
- **Blueprint Analysis**: Understand existing Blueprints with AI-powered analysis
- **Blueprint Modification**: Modify existing Blueprints using natural language instructions
- **C++ Code Generation**: Generate Unreal Engine C++ code from descriptions
- **Context Menu Integration**: Right-click on Blueprint assets to access Aerith functionality
- **Editor Panel**: Dedicated UI panel for interacting with Aerith

## Requirements

- Unreal Engine 5.7
- Anthropic Claude API key (sign up at https://console.anthropic.com/)

## Installation

1. The plugin is already installed in `Engine/Plugins/Aerith`
2. Open Unreal Engine 5.7
3. Go to **Edit → Plugins**
4. Search for "Airith"
5. Enable the plugin
6. Restart the editor

## Configuration

1. After enabling the plugin, go to **Edit → Project Settings**
2. Navigate to **Plugins → Aerith AI Assistant**
3. Enter your **Claude API Key**
4. (Optional) Adjust other settings:
   - **API Endpoint**: Default is Anthropic's API (usually no need to change)
   - **Model**: The Claude model to use (default: claude-3-5-sonnet-20241022)
   - **Max Tokens**: Maximum response length (default: 8192)
   - **Temperature**: AI creativity (0.0-1.0, default: 0.7)

## Usage

### Method 1: Editor Panel

1. Open Aerith panel via **Window → Aerith** in the main menu
2. (Optional) Select a Blueprint for context using the Blueprint picker
3. Enter your prompt in the text box
4. Click one of the action buttons:
   - **Send Prompt**: General AI assistance with optional Blueprint context
   - **Analyze Blueprint**: Get detailed analysis of the selected Blueprint
   - **Create New Blueprint**: Create a new Blueprint from your description
   - **Generate C++ Code**: Generate C++ code from your description

### Method 2: Context Menu

1. In the Content Browser, right-click on any Blueprint asset
2. Select **Aerith AI** section
3. Choose:
   - **Analyze with Aerith**: Get AI analysis of the Blueprint
   - **Modify with Aerith**: Enter instructions to modify the Blueprint

## Example Prompts

### Creating a New Blueprint
```
Create a health system with:
- Health variable (float, 0-100)
- MaxHealth variable (float)
- TakeDamage function that reduces health
- IsDead function that returns true if health is 0
```

### Modifying an Existing Blueprint
```
Add a stamina system:
- Stamina variable (float)
- RegenerateStamina function
- UseStamina function that takes an amount parameter
```

### Analyzing a Blueprint
```
What does this Blueprint do? What could be improved?
```

### Generating C++ Code
```
Create a custom ActorComponent that handles player inventory with:
- Add/Remove item functions
- Weight calculation
- Maximum capacity checking
```

## How It Works

1. **Blueprint Analysis**: Aerith reads Blueprint graphs, nodes, variables, functions, and components, converting them to structured JSON data
2. **AI Processing**: The JSON is sent to Claude API along with your prompt and system instructions
3. **Blueprint Modification**: Claude responds with structured instructions that Aerith executes:
   - Adding/removing variables
   - Creating functions
   - Adding components
   - Creating new nodes and connections

## Current Capabilities

Add variables to Blueprints
Create new functions
Add components to Actor Blueprints
Analyze Blueprint structure comprehensively
Generate C++ code
Create new Blueprint assets

## Limitations & Future Work

**Current Limitations**:
- Node creation and connection logic is basic - complex node graphs require manual refinement
- AI may need multiple iterations for complex modifications
- Some Unreal Engine-specific classes might not be recognized automatically
- Blueprint compilation may occasionally fail and require manual fixes

**Future Enhancements**:
- More sophisticated node placement algorithms
- Support for Blueprint interfaces and macros
- Enhanced C++ code integration
- Visual node graph generation
- Blueprint refactoring suggestions
- Integration with version control
- Custom training on your project's conventions

## Troubleshooting

### "API Key not configured" error
- Make sure you've entered your Claude API key in Project Settings → Plugins → Aerith

### Blueprint compilation errors after modification
- Aerith creates the structure but might not always connect nodes perfectly
- Open the Blueprint editor and manually fix any connection issues
- Check the Output Log for specific compilation errors

### Context menu doesn't appear
- Make sure the plugin is enabled
- Restart the editor after enabling
- Right-click specifically on Blueprint assets (not folders or other asset types)

### AI responses are slow or timeout
- This is normal for complex operations - Claude API responses can take 10-30 seconds
- Check your internet connection
- Verify your API key is valid and has available credits

## Privacy & Security

- Your prompts and Blueprint data are sent to Anthropic's Claude API
- No data is stored by the plugin - everything is processed in real-time
- API keys are stored in your project config (do not commit to version control!)
- Review Anthropic's privacy policy at https://www.anthropic.com/legal/privacy

## API Costs

- This plugin uses Anthropic's Claude API which has usage-based pricing
- Monitor your usage at https://console.anthropic.com/
- Typical cost per request: $0.01-0.10 depending on complexity
- Consider setting up usage limits in your Anthropic account

## Support & Contributing

This plugin is provided as-is for educational and development purposes.

**Issues & Feedback**:
- Report issues through your organization's standard channels
- Include UE version, plugin version, and reproduction steps

## License

Copyright Epic Games, Inc. All Rights Reserved.

## Credits

Developed using:
- Unreal Engine 5.7
- Blueprint Editor APIs
- Slate UI Framework

MaxNines 2025
---

**Note**: This is an experimental plugin. Always back up your Blueprints before using AI modifications, and review all changes before committing to your project.
