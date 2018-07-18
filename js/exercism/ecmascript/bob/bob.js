function getIsQuestion(message){
  return message.lastIndexOf("?") === (message.length - 1);
}

function getIsYell(message){
  return (message === message.toUpperCase()) && /[a-zA-Z]/.test(message);
}

function getIsSilence(message){
  return message.split(" ").join("") === "";
}

class Bob {
  hey(message) {
    let isQuestion = getIsQuestion(message);
    let isYell = getIsYell(message);
    let isSilence = getIsSilence(message);

    if(isQuestion && isYell){
      return "Calm down, I know what I'm doing!";
    }
    else if(isYell){
      return "Whoa, chill out!";
    }
    else if(isSilence){
      return "Fine. Be that way!";
    }
    else if(isQuestion){
      return "Sure.";
    }
    else{
      return "Whatever.";
    }
  }
}

export default Bob;

