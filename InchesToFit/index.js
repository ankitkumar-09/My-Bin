const convertFromFeet = () => {
    let feet = (document.getElementById("feet").value);
    
   
        document.getElementById("inches").value = feet * 12;


};

const convertFromInches = () => {
    let inches = (document.getElementById("inches").value);
  
        document.getElementById("feet").value = (inches / 12).toFixed(2);
  
};
