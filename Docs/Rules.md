# NO-AI PROJECT CHALLENGE

**Participant:** Ashwath Raj
**Environment:** Ubuntu Linux + Firefox + VS Code Insiders
**Purpose:** Build a complete software project without generative AI assistance and record the process as evidence.

---

## 1. Core Rule

The project must be developed **without intentional use of generative AI or LLM-based assistance**.

If a tool generates, completes, explains, debugs, designs, or modifies content using an AI/LLM, it is prohibited.

The challenge is about demonstrating my own ability to reason, design, implement, debug, and finish a project.

---

## 2. Strictly Forbidden

### AI Chat / LLMs

* ChatGPT
* Claude
* Google Gemini
* Microsoft Copilot
* Perplexity
* DeepSeek
* Grok
* Poe
* Character.AI
* Mistral AI
* Meta AI
* Hugging Face AI chat
* Any other LLM chatbot or equivalent service

### AI Search

Do not intentionally use:

* Google AI Overviews
* Bing Copilot answers
* Brave AI answers/summaries
* DuckDuckGo AI Assist
* Perplexity search
* AI-generated search summaries
* AI-generated answers embedded in search engines

### AI Coding Assistance

Forbidden:

* GitHub Copilot
* Copilot Chat
* Copilot autocomplete
* Gemini Code Assist
* Amazon Q
* Codeium / Windsurf AI
* Continue
* Cline
* Roo Code
* Tabnine AI
* Cody
* Claude Code
* AI-powered IDEs
* AI-powered terminal assistants
* AI-generated code completion

### AI-Generated Project Material

Do not use AI to generate:

* Source code
* Algorithms
* Architecture
* Database schemas
* Documentation
* README content
* Test cases
* Commit messages
* UI designs
* Prompts that generate project components
* Debugging solutions
* Explanations used to solve a problem

---

## 3. Allowed Resources

Normal developer resources are explicitly allowed.

### Documentation

* Official language documentation
* Official framework documentation
* Official API documentation
* Linux/Ubuntu documentation
* Man pages
* Books
* Tutorials written by humans

### Developer Resources

* GitHub repositories
* GitHub Issues
* Stack Overflow
* Normal web search
* Technical articles
* RFCs
* Academic papers

### Local Development Tools

* Compiler errors
* Runtime errors
* Debuggers
* GDB
* Valgrind
* Linters
* Formatters
* Language servers
* VS Code IntelliSense
* Git
* Terminal
* Build systems
* Test frameworks

A compiler or debugger providing diagnostic information is **not considered AI assistance**.

---

## 4. Browser Rules

Firefox is the only browser used during the challenge.

Configured protections:

* LeechBlock NG
* Disable AI

The browser must not be used to access blocked LLM services.

Normal web research remains permitted.

If an AI-generated answer appears accidentally in a search result, do not intentionally use it. Navigate to a normal human-written or official source instead.

---

## 5. VS Code Rules

Development will be performed using **VS Code Insiders**.

AI features must remain disabled.

Current configuration:

```json
{
    "chat.disableAIFeatures": true
}
```

No AI coding extensions may be installed during the challenge.

Normal development extensions are permitted, including:

* C/C++
* Python
* Pylance
* Python Debugger
* Python Environments
* ESLint
* Prettier
* Docker
* Containers

Installing an additional extension during the challenge requires that it provide conventional developer tooling and contain no generative AI functionality.

---

## 6. Recording Requirements

The development process should be recorded using OBS.

The recording should capture:

* VS Code
* Terminal
* Browser activity
* Project development
* Debugging
* Testing
* Git operations

The beginning of the first session should show:

```bash
code-insiders --list-extensions
git --version
python3 --version
g++ --version
```

This establishes the development environment.

---

## 7. Git Requirements

Git should be used from the beginning of the project.

The initial project state should be committed before substantial implementation.

Meaningful development milestones should receive commits.

Example:

```bash
git add .
git commit -m "Initialize project"
```

Then subsequent milestones should be committed separately.

Do not create a fake history at the end of the challenge.

The Git history should represent the actual development process.

---

## 8. Development Log

Maintain:

```text
DEVELOPMENT_LOG.md
```

Each session should record:

```text
Session:
Date:
Duration:

Goal:

Work completed:

Problems encountered:

How I solved them:

Resources consulted:

Git commit:
```

The purpose is to document the reasoning and development process rather than merely showing the final result.

---

## 9. Accidental AI Exposure

If AI-generated content appears accidentally:

1. Do not intentionally use it.
2. Navigate away if necessary.
3. Find a legitimate non-AI source.
4. Continue the challenge.

Accidental exposure does not automatically invalidate the challenge.

Intentional use does.

---

## 10. No "Just One Question"

The following are violations even if used only once:

> "I'll just ask ChatGPT how to fix this."

> "I'll just check what algorithm I should use."

> "I'll just ask Gemini to explain this error."

> "I'll use Copilot only for autocomplete."

> "I'll ask AI whether my approach is correct."

The challenge specifically exists to remove that escape hatch.

---

## 11. What Counts as Success

The challenge is successful when the project is:

* Implemented without generative AI assistance
* Functional
* Tested
* Documented
* Committed to Git
* Demonstrated in the recording

The goal is **not** to produce the fastest or prettiest code.

The goal is to demonstrate that I can independently take a project from:

```text
Idea
  ↓
Design
  ↓
Implementation
  ↓
Failure
  ↓
Debugging
  ↓
Testing
  ↓
Working Software
```

---

## 12. Integrity Rule

The challenge operates on an honor system supported by technical evidence.

No attempt will be made to claim that browser extensions or editor settings provide mathematically perfect proof of no-AI usage.

The evidence consists of:

* Continuous development recordings
* Browser restrictions
* VS Code configuration
* Extension list
* Terminal history where appropriate
* Git history
* Development log
* Final project

The standard is **honest, intentional compliance**, not pretending that a browser extension is a magical lie detector.

---

## 13. Challenge Start

Once the first project code is written, the challenge is considered **ACTIVE**.

From that point onward:

**No AI.**

Search. Read. Think. Debug. Build.

If the compiler destroys the code, fix it yourself.

---

**STATUS: READY TO START**
