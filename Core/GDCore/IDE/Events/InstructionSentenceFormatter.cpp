/*
 * GDevelop Core
 * Copyright 2008-2016 Florian Rival (Florian.Rival@gmail.com). All rights
 * reserved. This project is released under the MIT License.
 */

#if defined(GD_IDE_ONLY)
#include "GDCore/IDE/Events/InstructionSentenceFormatter.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <utility>
#include <vector>
#include "GDCore/CommonTools.h"
#include "GDCore/Extensions/Metadata/InstructionMetadata.h"
#include "GDCore/String.h"
#include "GDCore/Tools/Localization.h"
#include "GDCore/Tools/Log.h"

using namespace std;

namespace gd {

InstructionSentenceFormatter *InstructionSentenceFormatter::_singleton = NULL;

gd::String InstructionSentenceFormatter::Translate(
    const gd::Instruction &instr, const gd::InstructionMetadata &metadata) {
  gd::String out = metadata.GetSentence();
  if (out.empty())
    out = "   ";  // Prevent empty sentences that could trigger graphical
                  // glitches.

  // Replace _PARAMx_ placeholders by their values
  for (std::size_t i = 0; i < metadata.parameters.size(); ++i) {
    gd::String placeholder = "_PARAM" + gd::String::From(i) + "_";
    gd::String parameter = instr.GetParameter(i).GetPlainString();
    out = out.FindAndReplace(placeholder, parameter);
  }

  out = out.FindAndReplace("\n", " ");
  return out;
}

std::vector<std::pair<gd::String, gd::TextFormatting> >
InstructionSentenceFormatter::GetAsFormattedText(
    const Instruction &instr, const gd::InstructionMetadata &metadata) {
  std::vector<std::pair<gd::String, gd::TextFormatting> > formattedStr;

  gd::String sentence = metadata.GetSentence();
  std::replace(sentence.Raw().begin(), sentence.Raw().end(), '\n', ' ');

  size_t loopCount = 0;
  bool parse = true;
  while (parse) {
    if (loopCount > 40) {
      break;
    }
    loopCount++;

    // Search first parameter
    parse = false;
    size_t firstParamPosition = gd::String::npos;
    size_t firstParamIndex = gd::String::npos;
    for (std::size_t i = 0; i < metadata.parameters.size(); ++i) {
      size_t paramPosition =
          sentence.find("_PARAM" + gd::String::From(i) + "_");
      if (paramPosition < firstParamPosition) {
        firstParamPosition = paramPosition;
        firstParamIndex = i;
        parse = true;
      }
    }

    // When a parameter is found, complete formatted gd::String.
    if (parse) {
      if (firstParamPosition !=
          0)  // Add constant text before the parameter if any
      {
        TextFormatting format;
        formattedStr.push_back(
            std::make_pair(sentence.substr(0, firstParamPosition), format));
      }

      // Add the parameter
      TextFormatting format =
          GetFormattingFromType(metadata.parameters[firstParamIndex].type);
      format.userData = firstParamIndex;

      gd::String text = instr.GetParameter(firstParamIndex).GetPlainString();
      std::replace(text.Raw().begin(),
                   text.Raw().end(),
                   '\n',
                   ' ');  // Using the raw std::string inside gd::String (no
                          // problems because it's only ANSI characters)

      formattedStr.push_back(std::make_pair(text, format));
      gd::String placeholder =
          "_PARAM" + gd::String::From(firstParamIndex) + "_";
      sentence = sentence.substr(firstParamPosition + placeholder.length());
    } else if (!sentence.empty())  // No more parameter found: Add the end of
                                   // the sentence
    {
      TextFormatting format;
      formattedStr.push_back(std::make_pair(sentence, format));
    }
  }

  return formattedStr;
}

TextFormatting InstructionSentenceFormatter::GetFormattingFromType(
    const gd::String &type) {
  if (gd::ParameterMetadata::IsObject(type)) return typesFormatting["object"];

  return typesFormatting[type];
}

gd::String InstructionSentenceFormatter::LabelFromType(const gd::String &type) {
  if (type.empty())
    return "";
  else if (type == "expression")
    return _("Expression");
  else if (gd::ParameterMetadata::IsObject(type))
    return _("Object");
  else if (type == "behavior")
    return _("Behavior");
  else if (type == "operator")
    return _("Operator");
  else if (type == "relationalOperator")
    return _("Relational operator");
  else if (type == "file")
    return _("File");
  else if (type == "key")
    return _("Key");
  else if (type == "mouse")
    return _("Mouse button");
  else if (type == "yesorno")
    return _("Yes or no");
  else if (type == "police")
    return _("Font");
  else if (type == "color")
    return _("Color");
  else if (type == "trueorfalse")
    return _("True or False");
  else if (type == "string")
    return _("String");
  else if (type == "musicfile")
    return _("Music");
  else if (type == "soundfile")
    return _("Sound");
  else if (type == "password")
    return _("Password");
  else if (type == "layer")
    return _("Layer");
  else if (type == "joyaxis")
    return _("Joystick axis");
  else if (type == "objectvar")
    return _("Variable of the object");
  else if (type == "scenevar")
    return _("Scene variable");
  else if (type == "globalvar")
    return _("Global variable");

  return _("Unknown");
}

void InstructionSentenceFormatter::LoadTypesFormattingFromConfig() {
  // Load default configuration
  typesFormatting.clear();
  typesFormatting["expression"].SetColor(27, 143, 1).SetBold();
  typesFormatting["object"].SetColor(182, 97, 10).SetBold();
  typesFormatting["behavior"].SetColor(119, 119, 119).SetBold();
  typesFormatting["operator"].SetColor(55, 131, 211).SetBold();
  typesFormatting["objectvar"].SetColor(131, 55, 162).SetBold();
  typesFormatting["scenevar"].SetColor(131, 55, 162).SetBold();
  typesFormatting["globalvar"].SetColor(131, 55, 162).SetBold();
}

}  // namespace gd

#endif
