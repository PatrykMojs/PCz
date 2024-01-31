import React, {useState} from "react";
import { useNavigate, Link } from "react-router-dom";

const DeletePersonForm = () =>{
    const [personId, setPersonId] = useState('')
    const navigate = useNavigate()

    const handleSubmit = async (e: React.FormEvent) =>{
        e.preventDefault()

        try{
            const response = await fetch(`http://localhost:5147/PersonDelete/${personId}`,{
                method: "DELETE",
            })

            if(response.ok){
                navigate('/')
            }
        }catch(err){
            console.error(err)
        }
    }

    return(
        <>
            <h1>Usuń osobę!</h1>
            <form onSubmit={handleSubmit} className="PersonForm">
                <label>
                    Podaj Id: <br></br>
                    <input 
                        type="text" 
                        value={personId}
                        onChange={(e)=>setPersonId(e.target.value)}
                    />
                </label>
                <button type="submit">Usuń</button>
            </form>
            
            <div className="backLink">
                <Link to="/">Wróć do strony głównej</Link>
            </div>
        </>
    )
}

export default DeletePersonForm