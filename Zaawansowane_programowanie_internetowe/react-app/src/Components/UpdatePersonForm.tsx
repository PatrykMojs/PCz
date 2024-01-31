import React, {useState} from "react";
import { useNavigate, Link } from "react-router-dom";

const UpdatePersonForm = () =>{

    const [person, setPerson] = useState({
        id: '',
        firstName: '',
        lastName: '',
        dateOfBirth: new Date(),
        origin: '',
    })

    const navigate = useNavigate()

    const handleSubmit = async(e: React.FormEvent) =>{
        e.preventDefault()

        const response = await fetch(`http://localhost:5147/PersonUpdate/${person.id}`,{
            method: "PUT",
            headers:{
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({
                ...person,
                dateOfBirth: new Date(person.dateOfBirth)
            })
        })

        if(response.ok){
            navigate('/')
        }
    }

    return(
        <>
            <h1>Edytuj dane o osobie!</h1>
            <form onSubmit={handleSubmit} className="PersonForm">

                <label>
                    Wprowadź id: <br></br>
                    <input 
                        type="text" 
                        value={person.id}
                        onChange={(e)=>setPerson({...person, id: e.target.value})}
                        placeholder="Id"
                    />
                </label>

               <label>
                    Wprowadź imię osoby: <br></br>
                    <input 
                        type="text" 
                        value={person.firstName}
                        onChange={(e)=>setPerson({...person, firstName: e.target.value})}
                        placeholder="Imię"
                    />
               </label>

                <label>
                    Wporwadź nazwisko osoby: <br></br>
                    <input 
                        type="text" 
                        value={person.lastName}
                        onChange={(e)=>setPerson({...person, lastName: e.target.value})}
                        placeholder="Nazwisko"
                    />
                </label>

                <label>
                    Wprowadź date urodzenia: <br></br>
                    <input 
                        type="text" 
                        value={person.dateOfBirth.toISOString().split("T")[0]}
                        onChange={(e)=>setPerson({...person, dateOfBirth: new Date(e.target.value)})}
                        placeholder="Data urodzenia"
                    />
                </label>

                <label>
                    Wprowadź kraj pochodzenia osoby: <br></br>
                    <input 
                        type="text" 
                        value={person.origin}
                        onChange={(e)=>setPerson({...person, origin: e.target.value})}
                        placeholder="Pochodzenie"
                    />
                </label>

                <button type="submit">Edytuj</button>
            </form>
            
            <div className="backLink">
                <Link to="/">Wróć do strony głównej</Link>
            </div>
        </>
    )

}

export default UpdatePersonForm