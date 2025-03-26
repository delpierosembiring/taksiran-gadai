import { useState, useEffect } from "react";
import { Card, CardContent } from "@/components/ui/card";
import { Input } from "@/components/ui/input";

export default function TaksirGadai() {
    const [namaBarang, setNamaBarang] = useState("");
    const [kategori, setKategori] = useState("");
    const [hargaBaru, setHargaBaru] = useState("");
    const [umur, setUmur] = useState("");
    const [kondisi, setKondisi] = useState("");
    const [hargaTaksiran, setHargaTaksiran] = useState(null);
    const [bunga5, setBunga5] = useState(null);
    const [bunga10, setBunga10] = useState(null);

    useEffect(() = > {
        if (!hargaBaru || !umur || !kondisi) {
            setHargaTaksiran(null);
            setBunga5(null);
            setBunga10(null);
            return;
        }
        const penyusutan = kategori.toLowerCase() == = "elektronik" ? 0.2 : 0.12;
        const totalPenyusutan = hargaBaru * penyusutan * umur;
        const hargaSetelahPenyusutan = hargaBaru - totalPenyusutan;
        const hargaFinal = hargaSetelahPenyusutan * (kondisi / 100);
        setHargaTaksiran(hargaFinal);
        setBunga5(hargaFinal * 1.05);
        setBunga10(hargaFinal * 1.10);
    }, [hargaBaru, umur, kondisi, kategori]);

    return (
        <div className = "p-6 bg-blue-500 min-h-screen flex flex-col items-center justify-center">
        <img src = "/logo-gbo.png" alt = "Logo Gbo" className = "w-32 mb-4" / >
        <Card className = "p-4 bg-white shadow-lg rounded-lg">
        <CardContent>
        <h2 className = "text-xl font-bold mb-4">Taksir Harga Gadai< / h2>
        < Input placeholder = "Nama Barang" onChange = { (e) = > setNamaBarang(e.target.value) } / >
        < Input placeholder = "Kategori (Elektronik/Kendaraan)" onChange = { (e) = > setKategori(e.target.value) } / >
        < Input type = "number" placeholder = "Harga Baru (Rp)" onChange = { (e) = > setHargaBaru(parseFloat(e.target.value)) } / >
        < Input type = "number" placeholder = "Umur Barang (Tahun)" onChange = { (e) = > setUmur(parseFloat(e.target.value)) } / >
        < Input type = "number" placeholder = "Kondisi (%)" onChange = { (e) = > setKondisi(parseFloat(e.target.value)) } / >
    {hargaTaksiran != = null && (
        <div className = "mt-4">
        <p className = "text-lg font-bold">Harga Taksiran : Rp{ hargaTaksiran.toLocaleString() }< / p>
        <p className = "text-md font-bold text-green-600">Harga dengan Bunga 5 % : Rp{ bunga5.toLocaleString() }< / p>
        <p className = "text-md font-bold text-red-600">Harga dengan Bunga 10 % : Rp{ bunga10.toLocaleString() }< / p>
        < / div>
        )}
    < / CardContent>
        < / Card>
        < / div>
        );
}
